#include <bits/stdc++.h>

using namespace std;

const int s[] = {906609, 888888, 886688, 861168, 855558, 853358, 840048, 828828, 824428, 821128, 819918, 809908, 807708,
                 804408, 802208, 801108, 793397, 780087, 770077, 749947, 747747, 737737, 729927, 723327, 698896, 696696,
                 693396, 689986, 678876, 675576, 672276, 666666, 663366, 661166, 660066, 657756, 656656, 654456, 653356,
                 652256, 650056, 649946, 648846, 642246, 639936, 636636, 631136, 630036, 623326, 619916, 618816, 616616,
                 612216, 611116, 606606, 604406, 603306, 602206, 601106, 595595, 592295, 589985, 588885, 585585, 580085,
                 579975, 577775, 576675, 575575, 573375, 571175, 570075, 565565, 564465, 561165, 560065, 555555, 554455,
                 551155, 550055, 549945, 548845, 545545, 543345, 536635, 535535, 534435, 531135, 528825, 525525, 523325,
                 522225, 520025, 519915, 515515, 514415, 513315, 512215, 510015, 509905, 508805, 507705, 506605, 505505,
                 493394, 491194, 489984, 488884, 487784, 485584, 484484, 477774, 476674, 474474, 471174, 470074, 469964,
                 468864, 464464, 462264, 461164, 459954, 456654, 452254, 447744, 445544, 444444, 443344, 442244, 441144,
                 440044, 438834, 436634, 434434, 432234, 428824, 426624, 425524, 424424, 421124, 420024, 416614, 414414,
                 412214, 409904, 408804, 407704, 405504, 404404, 402204, 401104, 399993, 397793, 393393, 391193, 384483,
                 378873, 377773, 375573, 374473, 372273, 371173, 369963, 367763, 366663, 363363, 359953, 357753, 354453,
                 348843, 345543, 343343, 335533, 333333, 330033, 329923, 324423, 321123, 320023, 308803, 306603, 303303,
                 302203, 301103, 299992, 297792, 296692, 294492, 292292, 290092, 289982, 286682, 284482, 282282, 280082,
                 279972, 277772, 276672, 273372, 272272, 270072, 266662, 262262, 259952, 258852, 257752, 256652, 255552,
                 252252, 249942, 246642, 244442, 242242, 239932, 238832, 235532, 234432, 232232, 231132, 227722, 225522,
                 222222, 221122, 220022, 219912, 216612, 215512, 214412, 213312, 212212, 210012, 209902, 204402, 202202,
                 201102, 198891, 189981, 188881, 187781, 184481, 182281, 180081, 178871, 174471, 171171, 168861, 165561,
                 162261, 161161, 159951, 156651, 155551, 154451, 149941, 147741, 143341, 142241, 141141, 140041, 138831,
                 137731, 135531, 133331, 131131, 129921, 128821, 127721, 123321, 122221, 121121, 119911, 117711, 111111,
                 110011, 108801, 106601, 105501, 102201, 101101, 99999};

int main() {

    int n, num;
    cin >> n;
    while (n--) {
        cin >> num;
        for (const auto &j : s) {
            if (j < num) {
                cout << j << endl;
                break;
            }
        }
    }

    return 0;
}
