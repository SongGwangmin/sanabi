#include "block.h"

block blocks[147];

void init_blocks() {
    blocks[0].rt.left = 0;
    blocks[0].rt.top = 7845;
    blocks[0].rt.right = 182;
    blocks[0].rt.bottom = 7874;
    blocks[0].lava_plag = FALSE;
    blocks[0].floor_plag = FALSE;
    blocks[0].grass_plag = FALSE;

    blocks[1].rt.left = 176;
    blocks[1].rt.top = 7876;
    blocks[1].rt.right = 707;
    blocks[1].rt.bottom = 7905;
    blocks[1].lava_plag = FALSE;
    blocks[1].floor_plag = FALSE;
    blocks[1].grass_plag = FALSE;

    blocks[2].rt.left = 710;
    blocks[2].rt.top = 7747;
    blocks[2].rt.right = 721;
    blocks[2].rt.bottom = 7905;
    blocks[2].lava_plag = FALSE;
    blocks[2].floor_plag = FALSE;
    blocks[2].grass_plag = FALSE;

    blocks[3].rt.left = 722;
    blocks[3].rt.top = 7747;
    blocks[3].rt.right = 1371;
    blocks[3].rt.bottom = 7776;
    blocks[3].lava_plag = FALSE;
    blocks[3].floor_plag = FALSE;
    blocks[3].grass_plag = FALSE;

    blocks[4].rt.left = 1372;
    blocks[4].rt.top = 7618;
    blocks[4].rt.right = 1406;
    blocks[4].rt.bottom = 7746;
    blocks[4].lava_plag = FALSE;
    blocks[4].floor_plag = FALSE;
    blocks[4].grass_plag = FALSE;

    blocks[5].rt.left = 1407;
    blocks[5].rt.top = 7618;
    blocks[5].rt.right = 1692;
    blocks[5].rt.bottom = 7650;
    blocks[5].lava_plag = FALSE;
    blocks[5].floor_plag = FALSE;
    blocks[5].grass_plag = FALSE;

    blocks[6].rt.left = 1693;
    blocks[6].rt.top = 7618;
    blocks[6].rt.right = 1709;
    blocks[6].rt.bottom = 7682;
    blocks[6].lava_plag = FALSE;
    blocks[6].floor_plag = FALSE;
    blocks[6].grass_plag = FALSE;

    blocks[7].rt.left = 1710;
    blocks[7].rt.top = 7650;
    blocks[7].rt.right = 2814;
    blocks[7].rt.bottom = 7682;
    blocks[7].lava_plag = FALSE;
    blocks[7].floor_plag = FALSE;
    blocks[7].grass_plag = FALSE;

    blocks[8].rt.left = 2815;
    blocks[8].rt.top = 7492;
    blocks[8].rt.right = 2850;
    blocks[8].rt.bottom = 7682;
    blocks[8].lava_plag = FALSE;
    blocks[8].floor_plag = FALSE;
    blocks[8].grass_plag = FALSE;

    blocks[9].rt.left = 2851;
    blocks[9].rt.top = 7490;
    blocks[9].rt.right = 3254;
    blocks[9].rt.bottom = 7522;
    blocks[9].lava_plag = FALSE;
    blocks[9].floor_plag = FALSE;
    blocks[9].grass_plag = FALSE;

    blocks[10].rt.left = 3255;
    blocks[10].rt.top = 7458;
    blocks[10].rt.right = 3287;
    blocks[10].rt.bottom = 7522;
    blocks[10].lava_plag = FALSE;
    blocks[10].floor_plag = FALSE;
    blocks[10].grass_plag = FALSE;

    blocks[11].rt.left = 3288;
    blocks[11].rt.top = 7459;
    blocks[11].rt.right = 3435;
    blocks[11].rt.bottom = 7493;
    blocks[11].lava_plag = FALSE;
    blocks[11].floor_plag = FALSE;
    blocks[11].grass_plag = FALSE;

    blocks[12].rt.left = 3436;
    blocks[12].rt.top = 7459;
    blocks[12].rt.right = 3471;
    blocks[12].rt.bottom = 7969;
    blocks[12].lava_plag = FALSE;
    blocks[12].floor_plag = FALSE;
    blocks[12].grass_plag = FALSE;

    blocks[13].rt.left = 3472;
    blocks[13].rt.top = 7937;
    blocks[13].rt.right = 3835;
    blocks[13].rt.bottom = 7969;
    blocks[13].lava_plag = FALSE;
    blocks[13].floor_plag = FALSE;
    blocks[13].grass_plag = FALSE;

    blocks[14].rt.left = 3836;
    blocks[14].rt.top = 7937;
    blocks[14].rt.right = 3855;
    blocks[14].rt.bottom = 7969;
    blocks[14].lava_plag = FALSE;
    blocks[14].floor_plag = FALSE;
    blocks[14].grass_plag = FALSE;

    blocks[15].rt.left = 3856;
    blocks[15].rt.top = 7963;
    blocks[15].rt.right = 4365;
    blocks[15].rt.bottom = 7997;
    blocks[15].lava_plag = FALSE;
    blocks[15].floor_plag = FALSE;
    blocks[15].grass_plag = FALSE;

    blocks[16].rt.left = 4368;
    blocks[16].rt.top = 7882;
    blocks[16].rt.right = 4761;
    blocks[16].rt.bottom = 7913;
    blocks[16].lava_plag = FALSE;
    blocks[16].floor_plag = FALSE;
    blocks[16].grass_plag = FALSE;

    blocks[17].rt.left = 4761;
    blocks[17].rt.top = 7362;
    blocks[17].rt.right = 4794;
    blocks[17].rt.bottom = 7883;
    blocks[17].lava_plag = FALSE;
    blocks[17].floor_plag = FALSE;
    blocks[17].grass_plag = FALSE;

    blocks[18].rt.left = 4763;
    blocks[18].rt.top = 7000;
    blocks[18].rt.right = 4794;
    blocks[18].rt.bottom = 7361;
    blocks[18].lava_plag = FALSE;
    blocks[18].floor_plag = FALSE;
    blocks[18].grass_plag = FALSE;

    blocks[19].rt.left = 4304;
    blocks[19].rt.top = 6966;
    blocks[19].rt.right = 4763;
    blocks[19].rt.bottom = 6999;
    blocks[19].lava_plag = FALSE;
    blocks[19].floor_plag = FALSE;
    blocks[19].grass_plag = FALSE;

    blocks[20].rt.left = 4163;
    blocks[20].rt.top = 6967;
    blocks[20].rt.right = 4303;
    blocks[20].rt.bottom = 6999;
    blocks[20].lava_plag = FALSE;
    blocks[20].floor_plag = FALSE;
    blocks[20].grass_plag = FALSE;

    blocks[21].rt.left = 4128;
    blocks[21].rt.top = 6720;
    blocks[21].rt.right = 4162;
    blocks[21].rt.bottom = 6999;
    blocks[21].lava_plag = FALSE;
    blocks[21].floor_plag = FALSE;
    blocks[21].grass_plag = FALSE;

    blocks[22].rt.left = 4163;
    blocks[22].rt.top = 6720;
    blocks[22].rt.right = 4466;
    blocks[22].rt.bottom = 6754;
    blocks[22].lava_plag = FALSE;
    blocks[22].floor_plag = FALSE;
    blocks[22].grass_plag = FALSE;

    blocks[23].rt.left = 4467;
    blocks[23].rt.top = 6720;
    blocks[23].rt.right = 4483;
    blocks[23].rt.bottom = 6796;
    blocks[23].lava_plag = FALSE;
    blocks[23].floor_plag = FALSE;
    blocks[23].grass_plag = FALSE;

    blocks[24].rt.left = 4484;
    blocks[24].rt.top = 6762;
    blocks[24].rt.right = 5575;
    blocks[24].rt.bottom = 6796;
    blocks[24].lava_plag = FALSE;
    blocks[24].floor_plag = FALSE;
    blocks[24].grass_plag = FALSE;

    blocks[25].rt.left = 5584;
    blocks[25].rt.top = 6782;
    blocks[25].rt.right = 5810;
    blocks[25].rt.bottom = 6805;
    blocks[25].lava_plag = FALSE;
    blocks[25].floor_plag = FALSE;
    blocks[25].grass_plag = FALSE;

    blocks[26].rt.left = 5779;
    blocks[26].rt.top = 6216;
    blocks[26].rt.right = 5810;
    blocks[26].rt.bottom = 6771;
    blocks[26].lava_plag = FALSE;
    blocks[26].floor_plag = FALSE;
    blocks[26].grass_plag = FALSE;

    blocks[27].rt.left = 5425;
    blocks[27].rt.top = 6180;
    blocks[27].rt.right = 5778;
    blocks[27].rt.bottom = 6216;
    blocks[27].lava_plag = FALSE;
    blocks[27].floor_plag = FALSE;
    blocks[27].grass_plag = FALSE;

    blocks[28].rt.left = 5388;
    blocks[28].rt.top = 6033;
    blocks[28].rt.right = 5424;
    blocks[28].rt.bottom = 6216;
    blocks[28].lava_plag = FALSE;
    blocks[28].floor_plag = FALSE;
    blocks[28].grass_plag = FALSE;

    blocks[29].rt.left = 5425;
    blocks[29].rt.top = 6034;
    blocks[29].rt.right = 6416;
    blocks[29].rt.bottom = 6069;
    blocks[29].lava_plag = FALSE;
    blocks[29].floor_plag = FALSE;
    blocks[29].grass_plag = FALSE;

    blocks[30].rt.left = 6417;
    blocks[30].rt.top = 5924;
    blocks[30].rt.right = 6439;
    blocks[30].rt.bottom = 6032;
    blocks[30].lava_plag = FALSE;
    blocks[30].floor_plag = FALSE;
    blocks[30].grass_plag = FALSE;

    blocks[31].rt.left = 6415;
    blocks[31].rt.top = 5650;
    blocks[31].rt.right = 6439;
    blocks[31].rt.bottom = 5923;
    blocks[31].lava_plag = FALSE;
    blocks[31].floor_plag = FALSE;
    blocks[31].grass_plag = FALSE;

    blocks[32].rt.left = 6440;
    blocks[32].rt.top = 5651;
    blocks[32].rt.right = 6549;
    blocks[32].rt.bottom = 5686;
    blocks[32].lava_plag = FALSE;
    blocks[32].floor_plag = FALSE;
    blocks[32].grass_plag = FALSE;

    blocks[33].rt.left = 6551;
    blocks[33].rt.top = 5670;
    blocks[33].rt.right = 6682;
    blocks[33].rt.bottom = 5686;
    blocks[33].lava_plag = FALSE;
    blocks[33].floor_plag = FALSE;
    blocks[33].grass_plag = FALSE;

    blocks[34].rt.left = 6682;
    blocks[34].rt.top = 5544;
    blocks[34].rt.right = 6705;
    blocks[34].rt.bottom = 5686;
    blocks[34].lava_plag = FALSE;
    blocks[34].floor_plag = FALSE;
    blocks[34].grass_plag = FALSE;

    blocks[35].rt.left = 6679;
    blocks[35].rt.top = 5204;
    blocks[35].rt.right = 6705;
    blocks[35].rt.bottom = 5540;
    blocks[35].lava_plag = FALSE;
    blocks[35].floor_plag = FALSE;
    blocks[35].grass_plag = FALSE;

    blocks[36].rt.left = 6706;
    blocks[36].rt.top = 5204;
    blocks[36].rt.right = 7030;
    blocks[36].rt.bottom = 5237;
    blocks[36].lava_plag = FALSE;
    blocks[36].floor_plag = FALSE;
    blocks[36].grass_plag = FALSE;

    blocks[37].rt.left = 7031;
    blocks[37].rt.top = 5204;
    blocks[37].rt.right = 7067;
    blocks[37].rt.bottom = 5596;
    blocks[37].lava_plag = FALSE;
    blocks[37].floor_plag = FALSE;
    blocks[37].grass_plag = FALSE;

    blocks[38].rt.left = 7049;
    blocks[38].rt.top = 5597;
    blocks[38].rt.right = 7227;
    blocks[38].rt.bottom = 5630;
    blocks[38].lava_plag = FALSE;
    blocks[38].floor_plag = FALSE;
    blocks[38].grass_plag = FALSE;

    blocks[39].rt.left = 7228;
    blocks[39].rt.top = 5597;
    blocks[39].rt.right = 7260;
    blocks[39].rt.bottom = 5691;
    blocks[39].lava_plag = FALSE;
    blocks[39].floor_plag = FALSE;
    blocks[39].grass_plag = FALSE;

    blocks[40].rt.left = 7261;
    blocks[40].rt.top = 5669;
    blocks[40].rt.right = 7689;
    blocks[40].rt.bottom = 5691;
    blocks[40].lava_plag = FALSE;
    blocks[40].floor_plag = FALSE;
    blocks[40].grass_plag = FALSE;

    blocks[41].rt.left = 7690;
    blocks[41].rt.top = 5664;
    blocks[41].rt.right = 7720;
    blocks[41].rt.bottom = 5691;
    blocks[41].lava_plag = FALSE;
    blocks[41].floor_plag = FALSE;
    blocks[41].grass_plag = FALSE;

    blocks[42].rt.left = 7687;
    blocks[42].rt.top = 5018;
    blocks[42].rt.right = 7720;
    blocks[42].rt.bottom = 5656;
    blocks[42].lava_plag = FALSE;
    blocks[42].floor_plag = FALSE;
    blocks[42].grass_plag = FALSE;

    blocks[43].rt.left = 7721;
    blocks[43].rt.top = 5018;
    blocks[43].rt.right = 8030;
    blocks[43].rt.bottom = 5054;
    blocks[43].lava_plag = FALSE;
    blocks[43].floor_plag = FALSE;
    blocks[43].grass_plag = FALSE;

    blocks[44].rt.left = 8031;
    blocks[44].rt.top = 4928;
    blocks[44].rt.right = 8066;
    blocks[44].rt.bottom = 5054;
    blocks[44].lava_plag = FALSE;
    blocks[44].floor_plag = FALSE;
    blocks[44].grass_plag = FALSE;

    blocks[45].rt.left = 8067;
    blocks[45].rt.top = 4928;
    blocks[45].rt.right = 8147;
    blocks[45].rt.bottom = 4964;
    blocks[45].lava_plag = FALSE;
    blocks[45].floor_plag = FALSE;
    blocks[45].grass_plag = FALSE;

    blocks[46].rt.left = 8148;
    blocks[46].rt.top = 4928;
    blocks[46].rt.right = 8183;
    blocks[46].rt.bottom = 5018;
    blocks[46].lava_plag = FALSE;
    blocks[46].floor_plag = FALSE;
    blocks[46].grass_plag = FALSE;

    blocks[47].rt.left = 8184;
    blocks[47].rt.top = 4983;
    blocks[47].rt.right = 9219;
    blocks[47].rt.bottom = 5018;
    blocks[47].lava_plag = FALSE;
    blocks[47].floor_plag = FALSE;
    blocks[47].grass_plag = FALSE;

    blocks[48].rt.left = 9220;
    blocks[48].rt.top = 4560;
    blocks[48].rt.right = 9250;
    blocks[48].rt.bottom = 5018;
    blocks[48].lava_plag = FALSE;
    blocks[48].floor_plag = FALSE;
    blocks[48].grass_plag = FALSE;

    blocks[49].rt.left = 9251;
    blocks[49].rt.top = 4560;
    blocks[49].rt.right = 9884;
    blocks[49].rt.bottom = 4590;
    blocks[49].lava_plag = FALSE;
    blocks[49].floor_plag = FALSE;
    blocks[49].grass_plag = FALSE;

    blocks[50].rt.left = 9885;
    blocks[50].rt.top = 4560;
    blocks[50].rt.right = 9910;
    blocks[50].rt.bottom = 4639;
    blocks[50].lava_plag = FALSE;
    blocks[50].floor_plag = FALSE;
    blocks[50].grass_plag = FALSE;

    blocks[51].rt.left = 9911;
    blocks[51].rt.top = 4607;
    blocks[51].rt.right = 10566;
    blocks[51].rt.bottom = 4639;
    blocks[51].lava_plag = FALSE;
    blocks[51].floor_plag = FALSE;
    blocks[51].grass_plag = FALSE;

    blocks[52].rt.left = 10569;
    blocks[52].rt.top = 4607;
    blocks[52].rt.right = 10601;
    blocks[52].rt.bottom = 4639;
    blocks[52].lava_plag = FALSE;
    blocks[52].floor_plag = FALSE;
    blocks[52].grass_plag = FALSE;

    blocks[53].rt.left = 10566;
    blocks[53].rt.top = 4093;
    blocks[53].rt.right = 10601;
    blocks[53].rt.bottom = 4606;
    blocks[53].lava_plag = FALSE;
    blocks[53].floor_plag = FALSE;
    blocks[53].grass_plag = FALSE;

    blocks[54].rt.left = 10602;
    blocks[54].rt.top = 4093;
    blocks[54].rt.right = 11078;
    blocks[54].rt.bottom = 4127;
    blocks[54].lava_plag = FALSE;
    blocks[54].floor_plag = FALSE;
    blocks[54].grass_plag = FALSE;

    blocks[55].rt.left = 11079;
    blocks[55].rt.top = 3669;
    blocks[55].rt.right = 11110;
    blocks[55].rt.bottom = 4127;
    blocks[55].lava_plag = FALSE;
    blocks[55].floor_plag = FALSE;
    blocks[55].grass_plag = FALSE;

    blocks[56].rt.left = 10733;
    blocks[56].rt.top = 3669;
    blocks[56].rt.right = 11078;
    blocks[56].rt.bottom = 3701;
    blocks[56].lava_plag = FALSE;
    blocks[56].floor_plag = FALSE;
    blocks[56].grass_plag = FALSE;

    blocks[57].rt.left = 10701;
    blocks[57].rt.top = 3560;
    blocks[57].rt.right = 10732;
    blocks[57].rt.bottom = 3702;
    blocks[57].lava_plag = FALSE;
    blocks[57].floor_plag = FALSE;
    blocks[57].grass_plag = FALSE;

    blocks[58].rt.left = 10703;
    blocks[58].rt.top = 2859;
    blocks[58].rt.right = 10732;
    blocks[58].rt.bottom = 3559;
    blocks[58].lava_plag = FALSE;
    blocks[58].floor_plag = FALSE;
    blocks[58].grass_plag = FALSE;

    blocks[59].rt.left = 9698;
    blocks[59].rt.top = 2859;
    blocks[59].rt.right = 10702;
    blocks[59].rt.bottom = 2889;
    blocks[59].lava_plag = FALSE;
    blocks[59].floor_plag = FALSE;
    blocks[59].grass_plag = FALSE;

    blocks[60].rt.left = 9666;
    blocks[60].rt.top = 2801;
    blocks[60].rt.right = 9697;
    blocks[60].rt.bottom = 2890;
    blocks[60].lava_plag = FALSE;
    blocks[60].floor_plag = FALSE;
    blocks[60].grass_plag = FALSE;

    blocks[61].rt.left = 7756;
    blocks[61].rt.top = 2801;
    blocks[61].rt.right = 9665;
    blocks[61].rt.bottom = 2836;
    blocks[61].lava_plag = FALSE;
    blocks[61].floor_plag = FALSE;
    blocks[61].grass_plag = FALSE;

    blocks[62].rt.left = 5481;
    blocks[62].rt.top = 6421;
    blocks[62].rt.right = 5577;
    blocks[62].rt.bottom = 6457;
    blocks[62].lava_plag = FALSE;
    blocks[62].floor_plag = FALSE;
    blocks[62].grass_plag = FALSE;

    blocks[63].rt.left = 5578;
    blocks[63].rt.top = 6421;
    blocks[63].rt.right = 5615;
    blocks[63].rt.bottom = 6542;
    blocks[63].lava_plag = FALSE;
    blocks[63].floor_plag = FALSE;
    blocks[63].grass_plag = FALSE;

    blocks[64].rt.left = 5481;
    blocks[64].rt.top = 6506;
    blocks[64].rt.right = 5577;
    blocks[64].rt.bottom = 6542;
    blocks[64].lava_plag = FALSE;
    blocks[64].floor_plag = FALSE;
    blocks[64].grass_plag = FALSE;

    blocks[65].rt.left = 5444;
    blocks[65].rt.top = 6421;
    blocks[65].rt.right = 5480;
    blocks[65].rt.bottom = 6542;
    blocks[65].lava_plag = FALSE;
    blocks[65].floor_plag = FALSE;
    blocks[65].grass_plag = FALSE;

    blocks[66].rt.left = 0;
    blocks[66].rt.top = 95;
    blocks[66].rt.right = 2023;
    blocks[66].rt.bottom = 130;
    blocks[66].lava_plag = FALSE;
    blocks[66].floor_plag = FALSE;
    blocks[66].grass_plag = FALSE;

    blocks[67].rt.left = 0;
    blocks[67].rt.top = 481;
    blocks[67].rt.right = 169;
    blocks[67].rt.bottom = 516;
    blocks[67].lava_plag = FALSE;
    blocks[67].floor_plag = FALSE;
    blocks[67].grass_plag = FALSE;

    blocks[68].rt.left = 170;
    blocks[68].rt.top = 481;
    blocks[68].rt.right = 205;
    blocks[68].rt.bottom = 579;
    blocks[68].lava_plag = FALSE;
    blocks[68].floor_plag = FALSE;
    blocks[68].grass_plag = FALSE;

    blocks[69].rt.left = 0;
    blocks[69].rt.top = 545;
    blocks[69].rt.right = 169;
    blocks[69].rt.bottom = 579;
    blocks[69].lava_plag = FALSE;
    blocks[69].floor_plag = FALSE;
    blocks[69].grass_plag = FALSE;

    blocks[70].rt.left = 0;
    blocks[70].rt.top = 836;
    blocks[70].rt.right = 169;
    blocks[70].rt.bottom = 817;
    blocks[70].lava_plag = FALSE;
    blocks[70].floor_plag = FALSE;
    blocks[70].grass_plag = FALSE;

    blocks[71].rt.left = 170;
    blocks[71].rt.top = 836;
    blocks[71].rt.right = 199;
    blocks[71].rt.bottom = 934;
    blocks[71].lava_plag = FALSE;
    blocks[71].floor_plag = FALSE;
    blocks[71].grass_plag = FALSE;

    blocks[72].rt.left = 0;
    blocks[72].rt.top = 900;
    blocks[72].rt.right = 169;
    blocks[72].rt.bottom = 934;
    blocks[72].lava_plag = FALSE;
    blocks[72].floor_plag = FALSE;
    blocks[72].grass_plag = FALSE;

    blocks[73].rt.left = 832;
    blocks[73].rt.top = 390;
    blocks[73].rt.right = 1197;
    blocks[73].rt.bottom = 425;
    blocks[73].lava_plag = FALSE;
    blocks[73].floor_plag = FALSE;
    blocks[73].grass_plag = FALSE;

    blocks[74].rt.left = 1198;
    blocks[74].rt.top = 390;
    blocks[74].rt.right = 1229;
    blocks[74].rt.bottom = 459;
    blocks[74].lava_plag = FALSE;
    blocks[74].floor_plag = FALSE;
    blocks[74].grass_plag = FALSE;

    blocks[75].rt.left = 832;
    blocks[75].rt.top = 426;
    blocks[75].rt.right = 1197;
    blocks[75].rt.bottom = 459;
    blocks[75].lava_plag = FALSE;
    blocks[75].floor_plag = FALSE;
    blocks[75].grass_plag = FALSE;

    blocks[76].rt.left = 799;
    blocks[76].rt.top = 390;
    blocks[76].rt.right = 831;
    blocks[76].rt.bottom = 459;
    blocks[76].lava_plag = FALSE;
    blocks[76].floor_plag = FALSE;
    blocks[76].grass_plag = FALSE;

    blocks[77].rt.left = 500;
    blocks[77].rt.top = 832;
    blocks[77].rt.right = 769;
    blocks[77].rt.bottom = 867;
    blocks[77].lava_plag = FALSE;
    blocks[77].floor_plag = FALSE;
    blocks[77].grass_plag = FALSE;

    blocks[78].rt.left = 770;
    blocks[78].rt.top = 832;
    blocks[78].rt.right = 801;
    blocks[78].rt.bottom = 900;
    blocks[78].lava_plag = FALSE;
    blocks[78].floor_plag = FALSE;
    blocks[78].grass_plag = FALSE;

    blocks[79].rt.left = 500;
    blocks[79].rt.top = 868;
    blocks[79].rt.right = 769;
    blocks[79].rt.bottom = 900;
    blocks[79].lava_plag = FALSE;
    blocks[79].floor_plag = FALSE;
    blocks[79].grass_plag = FALSE;

    blocks[80].rt.left = 468;
    blocks[80].rt.top = 832;
    blocks[80].rt.right = 499;
    blocks[80].rt.bottom = 900;
    blocks[80].lava_plag = FALSE;
    blocks[80].floor_plag = FALSE;
    blocks[80].grass_plag = FALSE;

    blocks[81].rt.left = 1243;
    blocks[81].rt.top = 829;
    blocks[81].rt.right = 1510;
    blocks[81].rt.bottom = 864;
    blocks[81].lava_plag = FALSE;
    blocks[81].floor_plag = FALSE;
    blocks[81].grass_plag = FALSE;

    blocks[82].rt.left = 1511;
    blocks[82].rt.top = 829;
    blocks[82].rt.right = 1543;
    blocks[82].rt.bottom = 898;
    blocks[82].lava_plag = FALSE;
    blocks[82].floor_plag = FALSE;
    blocks[82].grass_plag = FALSE;

    blocks[83].rt.left = 1243;
    blocks[83].rt.top = 865;
    blocks[83].rt.right = 1543;
    blocks[83].rt.bottom = 898;
    blocks[83].lava_plag = FALSE;
    blocks[83].floor_plag = FALSE;
    blocks[83].grass_plag = FALSE;

    blocks[84].rt.left = 1210;
    blocks[84].rt.top = 829;
    blocks[84].rt.right = 1242;
    blocks[84].rt.bottom = 898;
    blocks[84].lava_plag = FALSE;
    blocks[84].floor_plag = FALSE;
    blocks[84].grass_plag = FALSE;

    blocks[85].rt.left = 1842;
    blocks[85].rt.top = 459;
    blocks[85].rt.right = 2023;
    blocks[85].rt.bottom = 494;
    blocks[85].lava_plag = FALSE;
    blocks[85].floor_plag = FALSE;
    blocks[85].grass_plag = FALSE;

    blocks[86].rt.left = 1805;
    blocks[86].rt.top = 459;
    blocks[86].rt.right = 1841;
    blocks[86].rt.bottom = 575;
    blocks[86].lava_plag = FALSE;
    blocks[86].floor_plag = FALSE;
    blocks[86].grass_plag = FALSE;

    blocks[87].rt.left = 1842;
    blocks[87].rt.top = 541;
    blocks[87].rt.right = 2023;
    blocks[87].rt.bottom = 575;
    blocks[87].lava_plag = FALSE;
    blocks[87].floor_plag = FALSE;
    blocks[87].grass_plag = FALSE;

    blocks[88].rt.left = 1848;
    blocks[88].rt.top = 820;
    blocks[88].rt.right = 2023;
    blocks[88].rt.bottom = 855;
    blocks[88].lava_plag = FALSE;
    blocks[88].floor_plag = FALSE;
    blocks[88].grass_plag = FALSE;

    blocks[89].rt.left = 1809;
    blocks[89].rt.top = 820;
    blocks[89].rt.right = 1847;
    blocks[89].rt.bottom = 936;
    blocks[89].lava_plag = FALSE;
    blocks[89].floor_plag = FALSE;
    blocks[89].grass_plag = FALSE;

    blocks[90].rt.left = 1848;
    blocks[90].rt.top = 902;
    blocks[90].rt.right = 2023;
    blocks[90].rt.bottom = 936;
    blocks[90].lava_plag = FALSE;
    blocks[90].floor_plag = FALSE;
    blocks[90].grass_plag = FALSE;

    blocks[91].rt.left = 0;
    blocks[91].rt.top = 1205;
    blocks[91].rt.right = 2024;
    blocks[91].rt.bottom = 1236;
    blocks[91].lava_plag = FALSE;
    blocks[91].floor_plag = FALSE;
    blocks[91].grass_plag = FALSE;

    blocks[92].rt.left = 7761;
    blocks[92].rt.top = 3210;
    blocks[92].rt.right = 7867;
    blocks[92].rt.bottom = 3244;
    blocks[92].lava_plag = FALSE;
    blocks[92].floor_plag = FALSE;
    blocks[92].grass_plag = FALSE;

    blocks[93].rt.left = 7868;
    blocks[93].rt.top = 3210;
    blocks[93].rt.right = 7900;
    blocks[93].rt.bottom = 3322;
    blocks[93].lava_plag = FALSE;
    blocks[93].floor_plag = FALSE;
    blocks[93].grass_plag = FALSE;

    blocks[94].rt.left = 7901;
    blocks[94].rt.top = 3321;
    blocks[94].rt.right = 9628;
    blocks[94].rt.bottom = 3351;
    blocks[94].lava_plag = FALSE;
    blocks[94].floor_plag = FALSE;
    blocks[94].grass_plag = FALSE;

    blocks[95].rt.left = 9629;
    blocks[95].rt.top = 3231;
    blocks[95].rt.right = 9663;
    blocks[95].rt.bottom = 3351;
    blocks[95].lava_plag = FALSE;
    blocks[95].floor_plag = FALSE;
    blocks[95].grass_plag = FALSE;

    blocks[96].rt.left = 9664;
    blocks[96].rt.top = 3231;
    blocks[96].rt.right = 10271;
    blocks[96].rt.bottom = 3265;
    blocks[96].lava_plag = FALSE;
    blocks[96].floor_plag = FALSE;
    blocks[96].grass_plag = FALSE;

    blocks[97].rt.left = 10272;
    blocks[97].rt.top = 3231;
    blocks[97].rt.right = 10303;
    blocks[97].rt.bottom = 3473;
    blocks[97].lava_plag = FALSE;
    blocks[97].floor_plag = FALSE;
    blocks[97].grass_plag = FALSE;

    blocks[98].rt.left = 10272;
    blocks[98].rt.top = 3474;
    blocks[98].rt.right = 10303;
    blocks[98].rt.bottom = 4138;
    blocks[98].lava_plag = FALSE;
    blocks[98].floor_plag = FALSE;
    blocks[98].grass_plag = FALSE;

    blocks[99].rt.left = 8828;
    blocks[99].rt.top = 4139;
    blocks[99].rt.right = 10308;
    blocks[99].rt.bottom = 4170;
    blocks[99].lava_plag = FALSE;
    blocks[99].floor_plag = FALSE;
    blocks[99].grass_plag = FALSE;

    blocks[100].rt.left = 8792;
    blocks[100].rt.top = 4139;
    blocks[100].rt.right = 8827;
    blocks[100].rt.bottom = 4676;
    blocks[100].lava_plag = FALSE;
    blocks[100].floor_plag = FALSE;
    blocks[100].grass_plag = FALSE;

    blocks[101].rt.left = 8456;
    blocks[101].rt.top = 4641;
    blocks[101].rt.right = 8791;
    blocks[101].rt.bottom = 4676;
    blocks[101].lava_plag = FALSE;
    blocks[101].floor_plag = FALSE;
    blocks[101].grass_plag = FALSE;

    blocks[102].rt.left = 8425;
    blocks[102].rt.top = 4641;
    blocks[102].rt.right = 8454;
    blocks[102].rt.bottom = 4835;
    blocks[102].lava_plag = FALSE;
    blocks[102].floor_plag = FALSE;
    blocks[102].grass_plag = FALSE;

    blocks[103].rt.left = 8254;
    blocks[103].rt.top = 4804;
    blocks[103].rt.right = 8424;
    blocks[103].rt.bottom = 4835;
    blocks[103].lava_plag = FALSE;
    blocks[103].floor_plag = FALSE;
    blocks[103].grass_plag = FALSE;

    blocks[104].rt.left = 8227;
    blocks[104].rt.top = 4804;
    blocks[104].rt.right = 8253;
    blocks[104].rt.bottom = 4868;
    blocks[104].lava_plag = FALSE;
    blocks[104].floor_plag = FALSE;
    blocks[104].grass_plag = FALSE;

    blocks[105].rt.left = 7942;
    blocks[105].rt.top = 4846;
    blocks[105].rt.right = 8226;
    blocks[105].rt.bottom = 4868;
    blocks[105].lava_plag = FALSE;
    blocks[105].floor_plag = FALSE;
    blocks[105].grass_plag = FALSE;

    blocks[106].rt.left = 7919;
    blocks[106].rt.top = 4846;
    blocks[106].rt.right = 7941;
    blocks[106].rt.bottom = 4955;
    blocks[106].lava_plag = FALSE;
    blocks[106].floor_plag = FALSE;
    blocks[106].grass_plag = FALSE;

    blocks[107].rt.left = 7558;
    blocks[107].rt.top = 4932;
    blocks[107].rt.right = 7918;
    blocks[107].rt.bottom = 4955;
    blocks[107].lava_plag = FALSE;
    blocks[107].floor_plag = FALSE;
    blocks[107].grass_plag = FALSE;

    blocks[108].rt.left = 7558;
    blocks[108].rt.top = 4956;
    blocks[108].rt.right = 7593;
    blocks[108].rt.bottom = 5351;
    blocks[108].lava_plag = FALSE;
    blocks[108].floor_plag = FALSE;
    blocks[108].grass_plag = FALSE;

    blocks[109].rt.left = 7239;
    blocks[109].rt.top = 5317;
    blocks[109].rt.right = 7557;
    blocks[109].rt.bottom = 5351;
    blocks[109].lava_plag = FALSE;
    blocks[109].floor_plag = FALSE;
    blocks[109].grass_plag = FALSE;

    blocks[110].rt.left = 7163;
    blocks[110].rt.top = 5350;
    blocks[110].rt.right = 7238;
    blocks[110].rt.bottom = 5372;
    blocks[110].lava_plag = FALSE;
    blocks[110].floor_plag = FALSE;
    blocks[110].grass_plag = FALSE;

    blocks[111].rt.left = 7136;
    blocks[111].rt.top = 4485;
    blocks[111].rt.right = 7162;
    blocks[111].rt.bottom = 5372;
    blocks[111].lava_plag = FALSE;
    blocks[111].floor_plag = FALSE;
    blocks[111].grass_plag = FALSE;

    blocks[112].rt.left = 5223;
    blocks[112].rt.top = 5626;
    blocks[112].rt.right = 5620;
    blocks[112].rt.bottom = 5913;
    blocks[112].lava_plag = FALSE;
    blocks[112].floor_plag = FALSE;
    blocks[112].grass_plag = FALSE;

    blocks[113].rt.left = 5060;
    blocks[113].rt.top = 5880;
    blocks[113].rt.right = 5222;
    blocks[113].rt.bottom = 5913;
    blocks[113].lava_plag = FALSE;
    blocks[113].floor_plag = FALSE;
    blocks[113].grass_plag = FALSE;

    blocks[114].rt.left = 5035;
    blocks[114].rt.top = 5880;
    blocks[114].rt.right = 5059;
    blocks[114].rt.bottom = 6228;
    blocks[114].lava_plag = FALSE;
    blocks[114].floor_plag = FALSE;
    blocks[114].grass_plag = FALSE;

    blocks[115].rt.left = 5059;
    blocks[115].rt.top = 6193;
    blocks[115].rt.right = 5106;
    blocks[115].rt.bottom = 6228;
    blocks[115].lava_plag = FALSE;
    blocks[115].floor_plag = FALSE;
    blocks[115].grass_plag = FALSE;

    blocks[116].rt.left = 5107;
    blocks[116].rt.top = 6193;
    blocks[116].rt.right = 5143;
    blocks[116].rt.bottom = 6528;
    blocks[116].lava_plag = FALSE;
    blocks[116].floor_plag = FALSE;
    blocks[116].grass_plag = FALSE;

    blocks[117].rt.left = 4810;
    blocks[117].rt.top = 6494;
    blocks[117].rt.right = 5106;
    blocks[117].rt.bottom = 6528;
    blocks[117].lava_plag = FALSE;
    blocks[117].floor_plag = FALSE;
    blocks[117].grass_plag = FALSE;

    blocks[118].rt.left = 4352;
    blocks[118].rt.top = 6459;
    blocks[118].rt.right = 4809;
    blocks[118].rt.bottom = 6494;
    blocks[118].lava_plag = FALSE;
    blocks[118].floor_plag = FALSE;
    blocks[118].grass_plag = FALSE;

    blocks[119].rt.left = 4103;
    blocks[119].rt.top = 6423;
    blocks[119].rt.right = 4362;
    blocks[119].rt.bottom = 6455;
    blocks[119].lava_plag = FALSE;
    blocks[119].floor_plag = FALSE;
    blocks[119].grass_plag = FALSE;

    blocks[120].rt.left = 4071;
    blocks[120].rt.top = 6065;
    blocks[120].rt.right = 4102;
    blocks[120].rt.bottom = 6453;
    blocks[120].lava_plag = FALSE;
    blocks[120].floor_plag = FALSE;
    blocks[120].grass_plag = FALSE;

    blocks[121].rt.left = 3846;
    blocks[121].rt.top = 6477;
    blocks[121].rt.right = 3877;
    blocks[121].rt.bottom = 7019;
    blocks[121].lava_plag = FALSE;
    blocks[121].floor_plag = FALSE;
    blocks[121].grass_plag = FALSE;

    blocks[122].rt.left = 3845;
    blocks[122].rt.top = 7020;
    blocks[122].rt.right = 3874;
    blocks[122].rt.bottom = 7338;
    blocks[122].lava_plag = FALSE;
    blocks[122].floor_plag = FALSE;
    blocks[122].grass_plag = FALSE;

    blocks[123].rt.left = 3875;
    blocks[123].rt.top = 7306;
    blocks[123].rt.right = 4219;
    blocks[123].rt.bottom = 7339;
    blocks[123].lava_plag = FALSE;
    blocks[123].floor_plag = FALSE;
    blocks[123].grass_plag = FALSE;

    blocks[124].rt.left = 4220;
    blocks[124].rt.top = 7291;
    blocks[124].rt.right = 4554;
    blocks[124].rt.bottom = 7324;
    blocks[124].lava_plag = FALSE;
    blocks[124].floor_plag = FALSE;
    blocks[124].grass_plag = FALSE;

    blocks[125].rt.left = 4555;
    blocks[125].rt.top = 7291;
    blocks[125].rt.right = 4590;
    blocks[125].rt.bottom = 7602;
    blocks[125].lava_plag = FALSE;
    blocks[125].floor_plag = FALSE;
    blocks[125].grass_plag = FALSE;

    blocks[126].rt.left = 4130;
    blocks[126].rt.top = 7568;
    blocks[126].rt.right = 4553;
    blocks[126].rt.bottom = 7602;
    blocks[126].lava_plag = FALSE;
    blocks[126].floor_plag = FALSE;
    blocks[126].grass_plag = FALSE;

    blocks[127].rt.left = 4095;
    blocks[127].rt.top = 7568;
    blocks[127].rt.right = 4129;
    blocks[127].rt.bottom = 7682;
    blocks[127].lava_plag = FALSE;
    blocks[127].floor_plag = FALSE;
    blocks[127].grass_plag = FALSE;

    blocks[128].rt.left = 3789;
    blocks[128].rt.top = 7647;
    blocks[128].rt.right = 4094;
    blocks[128].rt.bottom = 7682;
    blocks[128].lava_plag = FALSE;
    blocks[128].floor_plag = FALSE;
    blocks[128].grass_plag = FALSE;

    blocks[129].rt.left = 3753;
    blocks[129].rt.top = 7647;
    blocks[129].rt.right = 3789;
    blocks[129].rt.bottom = 7828;
    blocks[129].lava_plag = FALSE;
    blocks[129].floor_plag = FALSE;
    blocks[129].grass_plag = FALSE;

    blocks[130].rt.left = 3664;
    blocks[130].rt.top = 7795;
    blocks[130].rt.right = 3752;
    blocks[130].rt.bottom = 7828;
    blocks[130].lava_plag = FALSE;
    blocks[130].floor_plag = FALSE;
    blocks[130].grass_plag = FALSE;

    blocks[131].rt.left = 197;
    blocks[131].rt.top = 7353;
    blocks[131].rt.right = 233;
    blocks[131].rt.bottom = 7601;
    blocks[131].lava_plag = FALSE;
    blocks[131].floor_plag = FALSE;
    blocks[131].grass_plag = FALSE;

    blocks[132].rt.left = 234;
    blocks[132].rt.top = 7571;
    blocks[132].rt.right = 262;
    blocks[132].rt.bottom = 7600;
    blocks[132].lava_plag = FALSE;
    blocks[132].floor_plag = FALSE;
    blocks[132].grass_plag = FALSE;

    blocks[133].rt.left = 264;
    blocks[133].rt.top = 7571;
    blocks[133].rt.right = 297;
    blocks[133].rt.bottom = 7619;
    blocks[133].lava_plag = FALSE;
    blocks[133].floor_plag = FALSE;
    blocks[133].grass_plag = FALSE;

    blocks[134].rt.left = 298;
    blocks[134].rt.top = 7587;
    blocks[134].rt.right = 469;
    blocks[134].rt.bottom = 7621;
    blocks[134].lava_plag = FALSE;
    blocks[134].floor_plag = FALSE;
    blocks[134].grass_plag = FALSE;

    blocks[135].rt.left = 470;
    blocks[135].rt.top = 7476;
    blocks[135].rt.right = 504;
    blocks[135].rt.bottom = 7621;
    blocks[135].lava_plag = FALSE;
    blocks[135].floor_plag = FALSE;
    blocks[135].grass_plag = FALSE;

    blocks[136].rt.left = 3628;
    blocks[136].rt.top = 7185;
    blocks[136].rt.right = 3663;
    blocks[136].rt.bottom = 7828;
    blocks[136].lava_plag = FALSE;
    blocks[136].floor_plag = FALSE;
    blocks[136].grass_plag = FALSE;

    blocks[137].rt.left = 2595;
    blocks[137].rt.top = 7186;
    blocks[137].rt.right = 3627;
    blocks[137].rt.bottom = 7220;
    blocks[137].lava_plag = FALSE;
    blocks[137].floor_plag = FALSE;
    blocks[137].grass_plag = FALSE;

    blocks[138].rt.left = 2559;
    blocks[138].rt.top = 7185;
    blocks[138].rt.right = 2594;
    blocks[138].rt.bottom = 7312;
    blocks[138].lava_plag = FALSE;
    blocks[138].floor_plag = FALSE;
    blocks[138].grass_plag = FALSE;

    blocks[139].rt.left = 2229;
    blocks[139].rt.top = 7277;
    blocks[139].rt.right = 2558;
    blocks[139].rt.bottom = 7312;
    blocks[139].lava_plag = FALSE;
    blocks[139].floor_plag = FALSE;
    blocks[139].grass_plag = FALSE;

    blocks[140].rt.left = 2195;
    blocks[140].rt.top = 7277;
    blocks[140].rt.right = 2228;
    blocks[140].rt.bottom = 7378;
    blocks[140].lava_plag = FALSE;
    blocks[140].floor_plag = FALSE;
    blocks[140].grass_plag = FALSE;

    blocks[141].rt.left = 1901;
    blocks[141].rt.top = 7344;
    blocks[141].rt.right = 2194;
    blocks[141].rt.bottom = 7378;
    blocks[141].lava_plag = FALSE;
    blocks[141].floor_plag = FALSE;
    blocks[141].grass_plag = FALSE;

    blocks[142].rt.left = 1137;
    blocks[142].rt.top = 7314;
    blocks[142].rt.right = 1907;
    blocks[142].rt.bottom = 7342;
    blocks[142].lava_plag = FALSE;
    blocks[142].floor_plag = FALSE;
    blocks[142].grass_plag = FALSE;

    blocks[143].rt.left = 1137;
    blocks[143].rt.top = 7345;
    blocks[143].rt.right = 1170;
    blocks[143].rt.bottom = 7485;
    blocks[143].lava_plag = FALSE;
    blocks[143].floor_plag = FALSE;
    blocks[143].grass_plag = FALSE;

    blocks[144].rt.left = 990;
    blocks[144].rt.top = 7452;
    blocks[144].rt.right = 1136;
    blocks[144].rt.bottom = 7484;
    blocks[144].lava_plag = FALSE;
    blocks[144].floor_plag = FALSE;
    blocks[144].grass_plag = FALSE;

    blocks[145].rt.left = 954;
    blocks[145].rt.top = 7264;
    blocks[145].rt.right = 989;
    blocks[145].rt.bottom = 7487;
    blocks[145].lava_plag = FALSE;
    blocks[145].floor_plag = FALSE;
    blocks[145].grass_plag = FALSE;

    blocks[146].rt.left = 958;
    blocks[146].rt.top = 7076;
    blocks[146].rt.right = 989;
    blocks[146].rt.bottom = 7263;
    blocks[146].lava_plag = FALSE;
    blocks[146].floor_plag = FALSE;
    blocks[146].grass_plag = FALSE;

    for (int i = 0; i < 147; ++i) {
        if (blocks[i].rt.left > blocks[i].rt.right) {
            int il = blocks[i].rt.left;
            blocks[i].rt.left = blocks[i].rt.right;
            blocks[i].rt.right = il;

        }

        if (blocks[i].rt.top > blocks[i].rt.bottom) {
            int il = blocks[i].rt.top;
            blocks[i].rt.top = blocks[i].rt.bottom;
            blocks[i].rt.bottom = il;

        }
    }
}