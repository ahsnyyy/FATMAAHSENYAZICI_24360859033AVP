#include <stdio.h>
#include <math.h>

/* Fonksiyon Prototipleri */
void serbestDusme(double *g, char **gezegenler);
void yukariAtis(double *g, char **gezegenler);
void agirlik(double *g, char **gezegenler);
void potansiyelEnerji(double *g, char **gezegenler);
void hidrostatikBasinc(double *g, char **gezegenler);
void arsimet(double *g, char **gezegenler);
void sarkac(double *g, char **gezegenler);
void ipGerilmesi(double *g, char **gezegenler);
void asansor(double *g, char **gezegenler);

void menu()
{
    printf("\n------ DENEY MENUSU ------\n");
    printf("1 - Serbest Dusme Deneyi\n");
    printf("2 - Yukari Atis Deneyi\n");
    printf("3 - Agirlik Deneyi\n");
    printf("4 - Kutlecekimsel Potansiyel Enerji Deneyi\n");
    printf("5 - Hidrostatik Basinç Deneyi\n");
    printf("6 - Arsimet Kaldirma Kuvveti Deneyi\n");
    printf("7 - Basit Sarkac Periyodu Deneyi\n");
    printf("8 - Sabit Ip Gerilmesi Deneyi\n");
    printf("9 - Asansor Deneyi\n");
    printf("-1 - Cikis\n");
}

int main()
{
    char isim[50];
    int secim;

    /* Gezegenlerin yercekimi ivmeleri (m/s^2) */
    double g[8] = {3.7, 8.87, 9.81, 3.71, 24.79, 10.44, 8.69, 11.15};

    char *gezegenler[8] = {
        "Merkur", "Venus", "Dunya", "Mars",
        "Jupiter", "Saturn", "Uranus", "Neptun"
    };

    printf("Bilim insaninin adini giriniz: ");
    scanf(" %49[^\n]", isim);

    do
    {
        menu();
        printf("Seciminiz: ");
        scanf("%d", &secim);

        switch(secim)
        {
            case 1: serbestDusme(g, gezegenler); break;
            case 2: yukariAtis(g, gezegenler); break;
            case 3: agirlik(g, gezegenler); break;
            case 4: potansiyelEnerji(g, gezegenler); break;
            case 5: hidrostatikBasinc(g, gezegenler); break;
            case 6: arsimet(g, gezegenler); break;
            case 7: sarkac(g, gezegenler); break;
            case 8: ipGerilmesi(g, gezegenler); break;
            case 9: asansor(g, gezegenler); break;
            case -1:
                printf("\nProgram sonlandirildi. Iyi calismalar %s!\n", isim);
                break;
            default:
                printf("Gecersiz secim! Lutfen tekrar deneyiniz.\n");
        }

    } while(secim != -1);

    return 0;
}

/* ---------------- DENEY FONKSIYONLARI ---------------- */

void serbestDusme(double *g, char **gezegenler)
{
    double t;
    printf("Sure (s): ");
    scanf(" %lf", &t);
    t = (t < 0) ? -t : t;

    for(int i=0;i<8;i++)
    {
        double h = 0.5 * (*(g+i)) * t * t;
        printf("%s gezegeninde dusulen yol: %.2lf m\n", gezegenler[i], h);
    }
}

void yukariAtis(double *g, char **gezegenler)
{
    double v;
    printf("Ilk hiz (m/s): ");
    scanf(" %lf", &v);
    v = (v < 0) ? -v : v;

    for(int i=0;i<8;i++)
    {
        double h = (v*v) / (2 * (*(g+i)));
        printf("%s gezegeninde max yukseklik: %.2lf m\n", gezegenler[i], h);
    }
}

void agirlik(double *g, char **gezegenler)
{
    double m;
    printf("Kutle (kg): ");
    scanf(" %lf", &m);

    m = (m < 0) ? -m : m;

    for(int i=0;i<8;i++)
    {
        double G = m * (*(g+i));
        printf("%s gezegeninde agirlik: %.2lf N\n", *(gezegenler+i), G);
    }
}

void potansiyelEnerji(double *g, char **gezegenler)
{
    double m,h;
    printf("Kutle (kg): ");
    scanf(" %lf",&m);
    printf("Yukseklik (m): ");
    scanf(" %lf",&h);

    m=(m<0)?-m:m;
    h=(h<0)?-h:h;

    for(int i=0;i<8;i++)
    {
        double E = m * (*(g+i)) * h;
        printf("%s gezegeninde potansiyel enerji: %.2lf J\n", gezegenler[i], E);
    }
}

void hidrostatikBasinc(double *g, char **gezegenler)
{
    double rho,h;
    printf("Sivi yogunlugu (kg/m3): ");
    scanf(" %lf",&rho);
    printf("Derinlik (m): ");
    scanf(" %lf",&h);

    rho=(rho<0)?-rho:rho;
    h=(h<0)?-h:h;

    for(int i=0;i<8;i++)
    {
        double P = rho * (*(g+i)) * h;
        printf("%s gezegeninde hidrostatik basinc: %.2lf Pa\n", gezegenler[i], P);
    }
}

void arsimet(double *g, char **gezegenler)
{
    double rho,V;
    printf("Sivi yogunlugu (kg/m3): ");
    scanf(" %lf",&rho);
    printf("Batan hacim (m3): ");
    scanf(" %lf",&V);

    rho=(rho<0)?-rho:rho;
    V=(V<0)?-V:V;

    for(int i=0;i<8;i++)
    {
        double F = rho * (*(g+i)) * V;
        printf("%s gezegeninde kaldirma kuvveti: %.2lf N\n", gezegenler[i], F);
    }
}

void sarkac(double *g, char **gezegenler)
{
    double L;
    printf("Ip uzunlugu (m): ");
    scanf(" %lf",&L);
    L=(L<0)?-L:L;

    for(int i=0;i<8;i++)
    {
        double T = 2 * M_PI * sqrt(L / (*(g+i)));
        printf("%s gezegeninde sarkac periyodu: %.2lf s\n", gezegenler[i], T);
    }
}

void ipGerilmesi(double *g, char **gezegenler)
{
    double m;
    printf("Kutle (kg): ");
    scanf(" %lf",&m);
    m=(m<0)?-m:m;

    for(int i=0;i<8;i++)
    {
        double T = m * (*(g+i));
        printf("%s gezegeninde ip gerilmesi: %.2lf N\n", gezegenler[i], T);
    }
}

void asansor(double *g, char **gezegenler)
{
    double m,a;
    int yon;

    printf("Kutle (kg): ");
    scanf(" %lf",&m);
    printf("Asansor ivmesi (m/s2): ");
    scanf(" %lf",&a);

    m=(m<0)?-m:m;
    a=(a<0)?-a:a;

    printf("Asansor yonu (1: Yukari, 0: Asagi): ");
    scanf("%d",&yon);

    for(int i=0;i<8;i++)
    {
        double N;

        if(yon==1)
            N = m * ((*(g+i)) + a);
        else
            N = m * ((*(g+i)) - a);

        printf("%s gezegeninde hissedilen agirlik: %.2lf N\n",
               gezegenler[i], N);
    }
}
