#include <cstdio>

const int maxn = 1000000 + 5;

struct saveFactors {
    int evenSqrLen = 0;
    int allFactors = 0;
};

saveFactors sum[maxn];
int marked[maxn];

int gcd(int a, int b) {
    return (b > 0) ? gcd(b, a % b) : a;
}

int saveAns[] = {4, 16, 36, 64, 100, 144, 196, 256, 324, 400, 484, 576, 676, 784, 900, 1024, 1156, 1296, 1444, 1600,
                 1764, 1936, 2116, 2304, 2500, 2704, 2916, 3136, 3364, 3600, 3844, 4096, 4356, 4624, 4900, 5184, 5476,
                 5776, 6084, 6400, 6724, 7056, 7396, 7744, 8100, 8464, 8836, 9216, 9604, 10000, 10404, 10816, 11236,
                 11664, 12100, 12544, 12996, 13456, 13924, 14400, 14884, 15376, 15876, 16384, 16900, 17424, 17956,
                 18496, 19044, 19600, 20164, 20736, 21316, 21904, 22500, 23104, 23716, 24336, 24964, 25600, 26244,
                 26896, 27556, 28224, 28900, 29584, 30276, 30976, 31684, 32400, 33124, 33856, 34596, 35344, 36100,
                 36864, 37636, 38416, 39204, 40000, 40804, 41616, 42436, 43264, 44100, 44944, 45796, 46656, 47524,
                 48400, 49284, 50176, 51076, 51984, 52900, 53824, 54756, 55696, 56644, 57600, 58564, 59536, 60516,
                 61504, 62500, 63504, 64516, 65536, 66564, 67600, 68644, 69696, 70756, 71824, 72900, 73984, 75076,
                 76176, 77284, 78400, 79524, 80656, 81796, 82944, 84100, 85264, 86436, 87616, 88804, 90000, 91204,
                 92416, 93636, 94864, 96100, 97344, 98596, 99856, 101124, 102400, 103684, 104976, 106276, 107584,
                 108900, 110224, 111556, 112896, 114244, 115600, 116964, 118336, 119716, 121104, 122500, 123904, 125316,
                 126736, 128164, 129600, 131044, 132496, 133956, 135424, 136900, 138384, 139876, 141376, 142884, 144400,
                 145924, 147456, 148996, 150544, 152100, 153664, 155236, 156816, 158404, 160000, 161604, 163216, 164836,
                 166464, 168100, 169744, 171396, 173056, 174724, 176400, 178084, 179776, 181476, 183184, 184900, 186624,
                 188356, 190096, 191844, 193600, 195364, 197136, 198916, 200704, 202500, 204304, 206116, 207936, 209764,
                 211600, 213444, 215296, 217156, 219024, 220900, 222784, 224676, 226576, 228484, 230400, 232324, 234256,
                 236196, 238144, 240100, 242064, 244036, 246016, 248004, 250000, 252004, 254016, 256036, 258064, 260100,
                 262144, 264196, 266256, 268324, 270400, 272484, 274576, 276676, 278784, 280900, 283024, 285156, 287296,
                 289444, 291600, 293764, 295936, 298116, 300304, 302500, 304704, 306916, 309136, 311364, 313600, 315844,
                 318096, 320356, 322624, 324900, 327184, 329476, 331776, 334084, 336400, 338724, 341056, 343396, 345744,
                 348100, 350464, 352836, 355216, 357604, 360000, 362404, 364816, 367236, 369664, 372100, 374544, 376996,
                 379456, 381924, 384400, 386884, 389376, 391876, 394384, 396900, 399424, 401956, 404496, 407044, 409600,
                 412164, 414736, 417316, 419904, 422500, 425104, 427716, 430336, 432964, 435600, 438244, 440896, 443556,
                 446224, 448900, 451584, 454276, 456976, 459684, 462400, 465124, 467856, 470596, 473344, 476100, 478864,
                 481636, 484416, 487204, 490000, 492804, 495616, 498436, 501264, 504100, 506944, 509796, 512656, 515524,
                 518400, 521284, 524176, 527076, 529984, 532900, 535824, 538756, 541696, 544644, 547600, 550564, 553536,
                 556516, 559504, 562500, 565504, 568516, 571536, 574564, 577600, 580644, 583696, 586756, 589824, 592900,
                 595984, 599076, 602176, 605284, 608400, 611524, 614656, 617796, 620944, 624100, 627264, 630436, 633616,
                 636804, 640000, 643204, 646416, 649636, 652864, 656100, 659344, 662596, 665856, 669124, 672400, 675684,
                 678976, 682276, 685584, 688900, 692224, 695556, 698896, 702244, 705600, 708964, 712336, 715716, 719104,
                 722500, 725904, 729316, 732736, 736164, 739600, 743044, 746496, 749956, 753424, 756900, 760384, 763876,
                 767376, 770884, 774400, 777924, 781456, 784996, 788544, 792100, 795664, 799236, 802816, 806404, 810000,
                 813604, 817216, 820836, 824464, 828100, 831744, 835396, 839056, 842724, 846400, 850084, 853776, 857476,
                 861184, 864900, 868624, 872356, 876096, 879844, 883600, 887364, 891136, 894916, 898704, 902500, 906304,
                 910116, 913936, 917764, 921600, 925444, 929296, 933156, 937024, 940900, 944784, 948676, 952576, 956484,
                 960400, 964324, 968256, 972196, 976144, 980100, 984064, 988036, 992016, 996004, 1000000};

int main() {

    for (auto &p : saveAns) {
        marked[p] = 1;
    }

    int i, tmp;
    for (i = 1; i < maxn; i++)
        for (int j = 1; i * j < maxn; j++) {
            if (j != 1) {
                tmp = i * j;
                ++sum[tmp].allFactors;
                if (marked[i] == 1) {
                    ++sum[tmp].evenSqrLen;
                }
            }
        }

    int n, a, Gcd;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &a);
        if (sum[a].evenSqrLen == 0) {
            puts("0");
        } else {
            Gcd = gcd(sum[a].evenSqrLen, sum[a].allFactors);
            sum[a].evenSqrLen /= Gcd;
            sum[a].allFactors /= Gcd;
            printf("%d/%d\n", sum[a].evenSqrLen, sum[a].allFactors);
        }
    }


    return 0;
}
