#include "lowpassfilter_cofficient.h"

lowpassfilter_pDelayLinkList lowpassfilter_pDelay[8];     // 用于存储每个通道过去时刻滤波后的结果
bool LowPassFilterStatus = false;                          // FIR带通滤波状态标志
uint16_t FIR_Lowpassfilter_FilterLength = 782;             // FIR带通滤波器阶数
double   FIR_Lowpassfilter_Coefficient[782] =              // FIR带通滤波器权重系数
{
    3.121161986497e-08, 2.51363519765e-08, 6.72328608278e-09,-2.14108847491e-08,
    -5.193632337967e-08,-7.430109844721e-08,-7.784941051722e-08,-5.576965084202e-08,
    -8.593068291963e-09,5.414360757121e-08,1.150819350943e-07,  1.5326786924e-07,
     1.50573858187e-07, 9.85280643394e-08, 3.26844194223e-09,-1.134525483119e-07,
    -2.183254831947e-07,-2.752012038315e-07,-2.564176086068e-07,-1.534427564958e-07,
    1.681090007921e-08,2.128420191839e-07,3.775459654079e-07, 4.53785225957e-07,
    4.025967339622e-07,2.185938908558e-07,-6.283643756238e-08,-3.701431366633e-07,
    -6.123935268665e-07,-7.047606221546e-07,-5.959551288925e-07,-2.892308719462e-07,
    1.505861983722e-07,6.082622283504e-07,9.465974608244e-07,1.045680150179e-06,
    8.422158326409e-07,3.567208629594e-07,-3.014781170915e-07,-9.559213118506e-07,
    -1.408158834944e-06,-1.495472009232e-06,-1.14501830328e-06,-4.073247686847e-07,
    5.437011611933e-07,1.448354841379e-06,2.029386643299e-06,2.073776872536e-06,
    1.504724830968e-06,4.208068281635e-07,-9.133962871511e-07,-2.127920738852e-06,
    -2.846733648996e-06,-2.800025999876e-06,-1.91698486506e-06,-3.688919322534e-07,
    1.455851279602e-06,3.044578090089e-06, 3.90038657308e-06,3.692231017014e-06,
    2.371053032699e-06,2.135935983975e-07,-2.22666550749e-06,-4.256179097358e-06,
    -5.233565240494e-06,-4.76546076918e-06,-2.84786497103e-06,9.455502808529e-08,
    3.292832915924e-06,5.828519244217e-06,6.891486920782e-06,6.029987169694e-06,
    3.317884642575e-06,-6.183250012141e-07,-4.733684502159e-06,-7.835087445632e-06,
    -8.919955563528e-06,-7.489090148931e-06,-3.738747347293e-06, 1.43561830125e-06,
    6.641625455216e-06,1.035645750014e-05,1.136354103403e-05,9.136521568208e-06,
    4.052733912084e-06,-2.641236112011e-06,-9.122597429865e-06,-1.347926366811e-05,
    -1.426332084336e-05,-1.095363912518e-05,-4.184123192483e-06,4.348518643864e-06,
    1.229619342301e-05,1.729470685482e-05,1.765416620176e-05,1.290623359082e-05,
    4.036481668594e-06,-6.690779025972e-06,-1.629535174106e-05,-2.189654379632e-05,
    -2.156156538286e-05,-1.494108585327e-05,-3.489960117103e-06,9.822447923733e-06,
    2.126555686256e-05,2.737851986764e-05, 2.59979901555e-05,1.698230379705e-05,
    2.398677617424e-06,-1.391984167907e-05,-2.736347882072e-05,-3.383121660306e-05,
    -3.095882511428e-05,-1.892750254655e-05,-5.882820060439e-07,1.918146529446e-05,
    3.475498918831e-05,4.133829758457e-05,3.641789472108e-05,2.064390452177e-05,
    -2.146217171549e-06,-2.582776280704e-05,-4.36125008815e-05,-4.997215075643e-05,
    -4.23226382704e-05,-2.196444752075e-05,6.042242633516e-06,3.410023177791e-05,
    5.411159074538e-05,5.978894109324e-05,4.858899824336e-05,2.268399905501e-05,
    -1.137096801232e-05,-4.425982591835e-05,-6.642687806097e-05,-7.082310440609e-05,
    -5.50961019772e-05,-2.255578280892e-05,1.843806052835e-05,5.658458035169e-05,
    8.072714841916e-05,8.308133032957e-05,6.168082954944e-05,2.128812776351e-05,
    -2.758375221341e-05,-7.136640761282e-05,-9.716973040997e-05,-9.653609950529e-05,
    -6.813237151028e-05,-1.854165163561e-05,3.918215322647e-05,8.890702903902e-05,
    0.0001158941517183,0.0001111188558802,7.418688781648e-05,1.392698728993e-05,
    -5.36397337955e-05,-0.0001095130253934,-0.0001370151208131,-0.0001267129090068,
    -7.952238322472e-05,-7.003153193711e-06,7.139291831958e-05,0.0001334900119375,
    0.0001606148996564,0.0001431461723198,8.375391369059e-05,-2.72334362688e-06,
    -9.290475608959e-05,-0.000161135966148,-0.0001867351508132,-0.0001601838505614,
    -8.642923218122e-05,1.579860166421e-05,0.0001186606577363,0.0001927337601393,
    0.0002153683579694,0.0001775211917518,8.702496993939e-05,-3.282056925519e-05,
    -0.0001491632145831,-0.0002285429737579,-0.0002464489310059,-0.0001947764152004,
    -8.494342980806e-05,5.443742198965e-05,0.0001849261491676,0.0002687910873036,
     0.000279844114157,0.0002114839157904,7.951004087222e-05,-8.13450918356e-05,
    -0.0002264674788308,-0.0003136641738219,-0.0003153448169941,-0.0002270878247601,
    -6.997148743557e-05,0.0001142840088778,0.0002743020099561, 0.000363297228725,
    0.0003526564814496,0.0002409359769074, 5.54944790867e-05,-0.0001540351656839,
    -0.0003289333176768,-0.0004177642878485,-0.0003913900820327,-0.0002522742916746,
    -3.516507087857e-05,0.0002014156709101,0.0003908454042602,0.0004770684925231,
    0.0004310533286828,0.0002602415186379,7.988371507088e-06,-0.0002572740238621,
    -0.0004604942686645,-0.0005411322602866,-0.0004710420997633,-0.0002638642234656,
    2.711160989111e-05,0.0003224854169804,0.0005382996600016,0.0006097877106982,
    0.0005106320732239,0.0002620517943287,-7.129233502422e-05,-0.0003979474612844,
    -0.0006246373292875,-0.000682767475279,-0.0005489704425496,-0.0002535911252285,
    0.0001257938156591,0.0004845768348004,0.0007198321380802,0.0007596959863027,
    0.0005850674947097,0.0002371404734397,-0.0001919410581269,-0.0005833074823226,
    -0.0008241524315006,-0.0008400812876532,-0.000617787681284,-0.0002112217810366,
    0.0002711487451735,0.0006950911563219,0.0009378061402901,0.0009233073376844,
    0.0006458396186789,0.0001742104771309,-0.0003649293083436,-0.0008209012984091,
    -0.001060939147727,-0.001008626672402,-0.0006677641900925,-0.0001243214106405,
    0.0004749059209685,0.0009617415414878, 0.001193636551433,  0.00109515315768,
    0.0006819195622149,5.958906135999e-05,-0.0006028324593993,-0.001118660500056,
    -0.001335927581483,-0.001181854366867,-0.0006864614297134,2.216052486897e-05,
     0.000750623208249,  0.00129277506535, 0.001487795126879, 0.001267542852061,
    0.0006793160916654,-0.0001233496346606,-0.0009203961341843,-0.001485305220558,
    -0.001649191107429,-0.001350865196947,-0.0006581429366643,0.0002467056448516,
     0.001114535098841, 0.001697624579745, 0.001820059363719, 0.001430287186904,
     0.000620281389114,-0.0003953418623702,-0.001335778713514,-0.001931332662789,
    -0.002000368416695,-0.001504072609458,-0.0005626750521399,0.0005728730377004,
     0.001587347139324, 0.002188357734325, 0.002190157525874, 0.001570251937361,
     0.000481762168714,-0.0007835814382982,-0.001873123834592,-0.002471103522822,
    -0.002389601219642,-0.001626575155484,-0.0003733157313868, 0.001032657914379,
     0.002197918506377, 0.002782660475739, 0.002599100359739, 0.001670439747096,
    0.0002322070161908,-0.001326556585506,-0.002567852993047,-0.003127114555708,
    -0.002819412712096,-0.001698779383088,-5.205004198984e-05, 0.001673526118688,
      0.00299093850136, 0.003510008035256, 0.003051844602849, 0.001707889289168,
    -0.0001753442613164,-0.002084423823911,-0.003477960385372,-0.003939045400335,
     -0.00329854087728,-0.001693146844718, 0.000460828136063,     0.00257399884,
     0.004043875717307, 0.004425210110507, 0.003562940024195, 0.001648552768886,
    -0.0008193167119059,-0.003162985922811,-0.004710103126699,-0.004984601328801,
    -0.003850520395414,-0.001565951573505, 0.001272158469406, 0.003881669391335,
     0.005508444964065, 0.005641599558686, 0.004170088333308, 0.001433647511067,
    -0.001851352234878,-0.004776272332665,-0.006488180048283,-0.006434642213792,
     -0.00453614262801,-0.001233804452163, 0.002607524068386, 0.005921172644629,
     0.007729783096296, 0.007427530116013, 0.004973552967142,0.0009371917203594,
     -0.00362623906703,-0.007444248077983,-0.009373831432615,-0.008733637346014,
    -0.005527738405877,-0.0004914987470815, 0.005064927981818, 0.009585397912228,
      0.01168916581029,  0.01057427493971, 0.006289774634986,-0.0002082729020222,
    -0.007248905232846, -0.01285304640027, -0.01526072424052, -0.01344476866335,
    -0.007470323664015, 0.001410350135816,   0.0109768863711,  0.01854412018145,
      0.02164368283999,  0.01872335989286, 0.009686432450449,-0.003880190506166,
     -0.01887399231272, -0.03123442677902, -0.03678800203334, -0.03220273882891,
     -0.01583667013083,  0.01172254359814,  0.04756875898328,  0.08688422148659,
       0.1237761710157,   0.1523779270482,   0.1679851911385,   0.1679851911385,
       0.1523779270482,   0.1237761710157,  0.08688422148659,  0.04756875898328,
      0.01172254359814, -0.01583667013083, -0.03220273882891, -0.03678800203334,
     -0.03123442677902, -0.01887399231272,-0.003880190506166, 0.009686432450449,
      0.01872335989286,  0.02164368283999,  0.01854412018145,   0.0109768863711,
     0.001410350135816,-0.007470323664015, -0.01344476866335, -0.01526072424052,
     -0.01285304640027,-0.007248905232846,-0.0002082729020222, 0.006289774634986,
      0.01057427493971,  0.01168916581029, 0.009585397912228, 0.005064927981818,
    -0.0004914987470815,-0.005527738405877,-0.008733637346014,-0.009373831432615,
    -0.007444248077983, -0.00362623906703,0.0009371917203594, 0.004973552967142,
     0.007427530116013, 0.007729783096296, 0.005921172644629, 0.002607524068386,
    -0.001233804452163, -0.00453614262801,-0.006434642213792,-0.006488180048283,
    -0.004776272332665,-0.001851352234878, 0.001433647511067, 0.004170088333308,
     0.005641599558686, 0.005508444964065, 0.003881669391335, 0.001272158469406,
    -0.001565951573505,-0.003850520395414,-0.004984601328801,-0.004710103126699,
    -0.003162985922811,-0.0008193167119059, 0.001648552768886, 0.003562940024195,
     0.004425210110507, 0.004043875717307,     0.00257399884, 0.000460828136063,
    -0.001693146844718, -0.00329854087728,-0.003939045400335,-0.003477960385372,
    -0.002084423823911,-0.0001753442613164, 0.001707889289168, 0.003051844602849,
     0.003510008035256,  0.00299093850136, 0.001673526118688,-5.205004198984e-05,
    -0.001698779383088,-0.002819412712096,-0.003127114555708,-0.002567852993047,
    -0.001326556585506,0.0002322070161908, 0.001670439747096, 0.002599100359739,
     0.002782660475739, 0.002197918506377, 0.001032657914379,-0.0003733157313868,
    -0.001626575155484,-0.002389601219642,-0.002471103522822,-0.001873123834592,
    -0.0007835814382982, 0.000481762168714, 0.001570251937361, 0.002190157525874,
     0.002188357734325, 0.001587347139324,0.0005728730377004,-0.0005626750521399,
    -0.001504072609458,-0.002000368416695,-0.001931332662789,-0.001335778713514,
    -0.0003953418623702, 0.000620281389114, 0.001430287186904, 0.001820059363719,
     0.001697624579745, 0.001114535098841,0.0002467056448516,-0.0006581429366643,
    -0.001350865196947,-0.001649191107429,-0.001485305220558,-0.0009203961341843,
    -0.0001233496346606,0.0006793160916654, 0.001267542852061, 0.001487795126879,
      0.00129277506535, 0.000750623208249,2.216052486897e-05,-0.0006864614297134,
    -0.001181854366867,-0.001335927581483,-0.001118660500056,-0.0006028324593993,
    5.958906135999e-05,0.0006819195622149,  0.00109515315768, 0.001193636551433,
    0.0009617415414878,0.0004749059209685,-0.0001243214106405,-0.0006677641900925,
    -0.001008626672402,-0.001060939147727,-0.0008209012984091,-0.0003649293083436,
    0.0001742104771309,0.0006458396186789,0.0009233073376844,0.0009378061402901,
    0.0006950911563219,0.0002711487451735,-0.0002112217810366,-0.000617787681284,
    -0.0008400812876532,-0.0008241524315006,-0.0005833074823226,-0.0001919410581269,
    0.0002371404734397,0.0005850674947097,0.0007596959863027,0.0007198321380802,
    0.0004845768348004,0.0001257938156591,-0.0002535911252285,-0.0005489704425496,
    -0.000682767475279,-0.0006246373292875,-0.0003979474612844,-7.129233502422e-05,
    0.0002620517943287,0.0005106320732239,0.0006097877106982,0.0005382996600016,
    0.0003224854169804,2.711160989111e-05,-0.0002638642234656,-0.0004710420997633,
    -0.0005411322602866,-0.0004604942686645,-0.0002572740238621,7.988371507088e-06,
    0.0002602415186379,0.0004310533286828,0.0004770684925231,0.0003908454042602,
    0.0002014156709101,-3.516507087857e-05,-0.0002522742916746,-0.0003913900820327,
    -0.0004177642878485,-0.0003289333176768,-0.0001540351656839, 5.54944790867e-05,
    0.0002409359769074,0.0003526564814496, 0.000363297228725,0.0002743020099561,
    0.0001142840088778,-6.997148743557e-05,-0.0002270878247601,-0.0003153448169941,
    -0.0003136641738219,-0.0002264674788308,-8.13450918356e-05,7.951004087222e-05,
    0.0002114839157904, 0.000279844114157,0.0002687910873036,0.0001849261491676,
    5.443742198965e-05,-8.494342980806e-05,-0.0001947764152004,-0.0002464489310059,
    -0.0002285429737579,-0.0001491632145831,-3.282056925519e-05,8.702496993939e-05,
    0.0001775211917518,0.0002153683579694,0.0001927337601393,0.0001186606577363,
    1.579860166421e-05,-8.642923218122e-05,-0.0001601838505614,-0.0001867351508132,
    -0.000161135966148,-9.290475608959e-05,-2.72334362688e-06,8.375391369059e-05,
    0.0001431461723198,0.0001606148996564,0.0001334900119375,7.139291831958e-05,
    -7.003153193711e-06,-7.952238322472e-05,-0.0001267129090068,-0.0001370151208131,
    -0.0001095130253934,-5.36397337955e-05,1.392698728993e-05,7.418688781648e-05,
    0.0001111188558802,0.0001158941517183,8.890702903902e-05,3.918215322647e-05,
    -1.854165163561e-05,-6.813237151028e-05,-9.653609950529e-05,-9.716973040997e-05,
    -7.136640761282e-05,-2.758375221341e-05,2.128812776351e-05,6.168082954944e-05,
    8.308133032957e-05,8.072714841916e-05,5.658458035169e-05,1.843806052835e-05,
    -2.255578280892e-05,-5.50961019772e-05,-7.082310440609e-05,-6.642687806097e-05,
    -4.425982591835e-05,-1.137096801232e-05,2.268399905501e-05,4.858899824336e-05,
    5.978894109324e-05,5.411159074538e-05,3.410023177791e-05,6.042242633516e-06,
    -2.196444752075e-05,-4.23226382704e-05,-4.997215075643e-05,-4.36125008815e-05,
    -2.582776280704e-05,-2.146217171549e-06,2.064390452177e-05,3.641789472108e-05,
    4.133829758457e-05,3.475498918831e-05,1.918146529446e-05,-5.882820060439e-07,
    -1.892750254655e-05,-3.095882511428e-05,-3.383121660306e-05,-2.736347882072e-05,
    -1.391984167907e-05,2.398677617424e-06,1.698230379705e-05, 2.59979901555e-05,
    2.737851986764e-05,2.126555686256e-05,9.822447923733e-06,-3.489960117103e-06,
    -1.494108585327e-05,-2.156156538286e-05,-2.189654379632e-05,-1.629535174106e-05,
    -6.690779025972e-06,4.036481668594e-06,1.290623359082e-05,1.765416620176e-05,
    1.729470685482e-05,1.229619342301e-05,4.348518643864e-06,-4.184123192483e-06,
    -1.095363912518e-05,-1.426332084336e-05,-1.347926366811e-05,-9.122597429865e-06,
    -2.641236112011e-06,4.052733912084e-06,9.136521568208e-06,1.136354103403e-05,
    1.035645750014e-05,6.641625455216e-06, 1.43561830125e-06,-3.738747347293e-06,
    -7.489090148931e-06,-8.919955563528e-06,-7.835087445632e-06,-4.733684502159e-06,
    -6.183250012141e-07,3.317884642575e-06,6.029987169694e-06,6.891486920782e-06,
    5.828519244217e-06,3.292832915924e-06,9.455502808529e-08,-2.84786497103e-06,
    -4.76546076918e-06,-5.233565240494e-06,-4.256179097358e-06,-2.22666550749e-06,
    2.135935983975e-07,2.371053032699e-06,3.692231017014e-06, 3.90038657308e-06,
    3.044578090089e-06,1.455851279602e-06,-3.688919322534e-07,-1.91698486506e-06,
    -2.800025999876e-06,-2.846733648996e-06,-2.127920738852e-06,-9.133962871511e-07,
    4.208068281635e-07,1.504724830968e-06,2.073776872536e-06,2.029386643299e-06,
    1.448354841379e-06,5.437011611933e-07,-4.073247686847e-07,-1.14501830328e-06,
    -1.495472009232e-06,-1.408158834944e-06,-9.559213118506e-07,-3.014781170915e-07,
    3.567208629594e-07,8.422158326409e-07,1.045680150179e-06,9.465974608244e-07,
    6.082622283504e-07,1.505861983722e-07,-2.892308719462e-07,-5.959551288925e-07,
    -7.047606221546e-07,-6.123935268665e-07,-3.701431366633e-07,-6.283643756238e-08,
    2.185938908558e-07,4.025967339622e-07, 4.53785225957e-07,3.775459654079e-07,
    2.128420191839e-07,1.681090007921e-08,-1.534427564958e-07,-2.564176086068e-07,
    -2.752012038315e-07,-2.183254831947e-07,-1.134525483119e-07, 3.26844194223e-09,
     9.85280643394e-08, 1.50573858187e-07,  1.5326786924e-07,1.150819350943e-07,
    5.414360757121e-08,-8.593068291963e-09,-5.576965084202e-08,-7.784941051722e-08,
    -7.430109844721e-08,-5.193632337967e-08,-2.14108847491e-08, 6.72328608278e-09,
     2.51363519765e-08,3.121161986497e-08
};