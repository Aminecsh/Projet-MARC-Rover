// moves.c

#include "moves.h"

/* Prototypes des fonctions locales */
t_orientation tourner(t_orientation ori, t_deplacement deplacement);
t_localisation deplacer(t_localisation loc, t_deplacement deplacement, t_map carte);

/* Définitions des fonctions locales */

t_orientation tourner(t_orientation ori, t_deplacement deplacement)
{
    int resultat;
    switch (deplacement)
    {
        case TOURNER_GAUCHE:
            resultat = 3; // Équivalent à -1 mod 4
            break;
        case TOURNER_DROITE:
            resultat = 1;
            break;
        case DEMI_TOUR:
            resultat = 2;
            break;
        default:
            resultat = 0;
            break;
    }
    return (ori + resultat) % 4;
}

t_localisation deplacer(t_localisation loc, t_deplacement deplacement, t_map carte)
{
    t_position res = loc.pos;
    int distance = 0;

    switch (deplacement)
    {
        case AVANCER_10:
            distance = 1;
            break;
        case AVANCER_20:
            distance = 2;
            break;
        case AVANCER_30:
            distance = 3;
            break;
        case RECULER_10:
            distance = -1;
            break;
        default:
            break;
    }

    if (distance != 0)
    {
        switch (loc.ori)
        {
            case NORD:
                res.y -= distance;
                break;
            case EST:
                res.x += distance;
                break;
            case SUD:
                res.y += distance;
                break;
            case OUEST:
                res.x -= distance;
                break;
        }
    }

    // Vérifier la pente à la nouvelle position
    if (estLocalisationValide(res, carte.x_max, carte.y_max))
    {
        t_direction_pente pente = carte.pentes[res.y][res.x];
        if (pente != PAS_DE_PENTE)
        {
            // Avancer d'une étape supplémentaire dans la direction de la pente
            switch (pente)
            {
                case DESCEND_NORD:
                    res.y -= 1;
                    break;
                case DESCEND_EST:
                    res.x += 1;
                    break;
                case DESCEND_SUD:
                    res.y += 1;
                    break;
                case DESCEND_OUEST:
                    res.x -= 1;
                    break;
                default:
                    break;
            }
        }
    }

    return loc_init(res.x, res.y, loc.ori);
}

/* Définitions des fonctions exportées */

const char *obtenirDeplacementEnChaine(t_deplacement deplacement)
{
    return _deplacements[deplacement];
}

t_localisation mouvement(t_localisation loc, t_deplacement deplacement, t_map carte)
{
    t_orientation nouvelle_ori = tourner(loc.ori, deplacement);
    t_localisation nouvelle_loc = deplacer(loc_init(loc.pos.x, loc.pos.y, nouvelle_ori), deplacement, carte);
    return nouvelle_loc;
}

void mettreAJourLocalisation(t_localisation *p_loc, t_deplacement deplacement, t_map carte)
{
    *p_loc = mouvement(*p_loc, deplacement, carte);
}
