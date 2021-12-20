#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, long long k)
    {
        vector<int> ans(nums.size(), -1);

        if (long(2 * (long)k + 1) > nums.size())
            return ans;
        long long left = 0, right = 2 * k + 1;
        long long sum = accumulate(nums.begin(), nums.begin() + right, (long long)0);
        int insertNode = k;
        for (; right <= nums.size();)
        {
            ans[insertNode] = sum / long(2 * (long)k + 1);
            if (right == nums.size())
                break;
            sum -= nums[left++];
            sum += nums[right++];
            insertNode++;
        }
        return ans;
    }
};

//int main(void)
//{
//    vector<int> nums = {4744,3044,7550,8264,29,9001,8641,5079,9237,4205,5727,8853,688,628,7828,6573,6256,5212,9619,8159,5190,8546,28,648,8114,580,8632,3343,770,1446,8899,9970,2906,843,2404,127,8940,5098,9612,3268,9491,8149,7510,2865,8667,6498,1763,3743,7225,1829,1191,4493,9579,6116,3635,4853,1929,296,8883,5573,9605,6134,963,1896,3274,1782,866,2682,6717,8407,4254,5079,1049,27,9959,3343,6005,2896,1131,4740,1924,200,2446,6145,7540,8257,6045,3882,5379,6183,5724,7643,2700,5333,2485,8130,1023,6676,9704,1142,1772,5041,8645,4874,9844,1506,4364,8621,8084,7009,9371,2596,1955,2243,6277,6468,6934,9756,1886,3650,3889,3118,5374,6321,7138,4632,4631,4096,1856,8021,1644,3269,9086,481,1825,2123,1771,1591,9657,7293,5190,1102,6443,9753,7102,3915,6715,4705,8382,3062,6308,7563,9817,5425,2202,6595,866,8407,71,3012,1963,3858,5330,560,2158,7738,6747,80,2432,8046,5119,8772,1162,5080,4841,7604,137,3798,7465,1431,1287,1518,9557,1088,6317,5863,5368,4198,9463,3418,3655,2630,4754,605,5264,5105,530,2455,396,6238,1899,3573,4882,4344,8708,8935,809,8262,7221,5789,937,7515,1770,4678,6814,185,3305,423,5150,7901,4612,312,2239,2144,9636,9719,9848,8448,79,8239,3256,4123,2594,3533,7540,1509,3890,9463,7219,7773,1866,4113,6276,5645,3973,9697,7233,1432,6111,4471,4998,8602,4570,83,7664,8812,9850,5836,6794,2823,2028,867,8149,7895,5021,3148,4922,7338,8413,3883,2293,5368,6079,7999,8472,9430,1787,9125,3056,7925,363,7696,3601,7417,8658,4967,9403,4917,4203,3210,9244,883,8515,9131,4602,1671,2701,4332,7101,7565,8139,1698,6632,7768,9930,7656,9910,1884,2956,4202,8424,1715,5814,3852,28,5631,6110,1026,903,9754,403,7377,8592,7472,3610,1380,7003,186,3697,6702,391,8766,9631,3170,2171,7754,2743,536,9975,8163,7537,282,9960,4734,7215,5898,4898,2409,702,3179,9949,9605,3421,9186,2977,289,9061,9933,1273,1891,8390,9490,1829,5401,971,9111,9538,9560,1373,47,8943,7772,5803,980,7036,7077,5944,1994,5318,6213,7601,132,9334,3469,374,5665,2265,6023,4574,2959,1354,8332,5096,8162,2389,46,4103,2578,7527,1365,6899,1647,3206,4081,1470,6015,8989,2462,4036,5934,5609,3057,2407,5612,1678,4375,8410,7264,2151,7887,1716,5514,1691,3763,3347,7771,3523,7653,6032,5099,5733,8642,452,5633,4402,4662,3569,1626,5995,8270,713,9407,3358,4834,3535,1747,5904,6016,6426,1709,366,1669,6556,3461,2498,2751,2714,6015,2538,6575,3587,564,4712,9482,9168,3555,2237,281,727,9675,6702,2760,3717,4787,4859,2114,8392,7511,945,7204,7738,2895,1814,1839,9649,6042,2569,4243,9127,293,3955,9921,4457,5533,3194,825,2026,6158,3430,2303,2691,5088,592,8680,3464,132,3032,1380,6280,9214,7693,3017,9857,9176,2740,6505,553,3656,6079,4741,4065,2914,6555,7468,9076,1689,9903,7653,71,4498,4954,7759,4493,9167,1245,16,5940,9923,5728,5213,4165,5557,1657,2089,5710,23,7563,4425,9690,2887,7896,6514,5145,5606,1825,2491,5770,7800,9821,1780,2394,3600,9321,2791,1841,6103,2883,469,1175,4720,1963,1397,8773,3917,8500,3536,2001,7946,8840,9856,5167,5141,7100,1551,5924,8597,9932,942,7617,2972,2179,1131,3049,6518,979,7417,1660,1331,3085,3148,997,321,2663,281,7334,9828,6199,4781,4644,121,1057,9896,2997,6552,2621,3548,3660,1760,9688,2758,7677,9127,6748,509,2762,2004,3482,4772,343,6936,1097,8397,7573,7090,1390,4377,9696,2722,2999,7769,4530,9133,964,6084,9035,5805,8127,5848,6348,2679,2283,8274,5040,409,9735,1032,8936,6954,2386,903,853,6905,6919,8693,3532,3403,6576,1699,6708,3717,4280,463,3391,780,9863,8841,8734,6905,6857,6422,1223,7631,1103,3030,2743,7504,2835,607,1494,8210,190,3976,2892,6715,895,5793,9582,7575,112,5202,7987,6128,5908,9458,9126,4048,3483,2686,6926,3273,1193,1241,189,9169,439,151,8355,1639,655,5367,3735,4697,3752,763,6930,2789,1459,280,311,4572,6668,7941,5842,5934,8804,4150,3570,8158,7066,4888,5299,1935,7924,7820,6244,6621,17,2154,9834,9518,9056,4176,9523,8990,3772,6237,6494,6157,5542,6776,4209,9247,1238,8044,3872,8583,4804,3276,460,1872,7452,7055,148,618,7762,1123,5568,1297,5833,681,9363,9038,9571,4421,8426,2730,2927,6410,9136,6917,1766,8536,3763,5633,9755,6585,3555,3026,2746,2605,3434,676,202,2481,663,6734,1588,5798,8463,6411,9380,5851,9234,4843,7660,2137,9322,9755,814,2264,5175,5599,3569,8175,6575,9354,4069,5176,3338,3200,2529,7332,5312,6243,4965,688,6395,4796,981,8219,197,4481,5669,8082,6895,2093,7959,6123,2859,2045,4147,1610,3000,4109,5154,5410,8587,3285,9558,6064,1003,5292,1792,7704,2599,9238,6807,585,1368,1302,4311,9448,3582,7252,3911,5423,6899,3396,4729,1077,9636,5101,776,5036,4866,2772,4552,142,4599,4214,7392,92,8869,3334,7523,2451,3880,2353,5485,6217,9886,4138,120,5030,9640,493,3754,1058,699,1990,885,1595,4980,7250,5899,608,1331,2581,5625,4385,6647,4856,7148,9272,2285,209,8582,5957,4211,1695,7471,3237,4761,6384,6284,3457,2276,1805,9442,4388,8114,3830,1760,22,2962,7407,962,5626,9042,8667,3676,4020,1371,1318,9658,642,9746,1021,9361,3887,4092,1060,6465,8170,3524,4841,3529,7245,5041,4422,7480,3328,9401,2014,8462,2378,7964,1516,4401,1513,7874,5297,3264,9532,9012,6686,2682,5603,4431,3652,7402,5229,2864,6237,560,328,4997,7050,6864,6786,9935,8686,4263,325,3959,2669,8921,6487,8227,2038,2881,1200,5996,792,7587,1324,9910,1407,4464,3399,4793,7043,8420,4167,5654,6811,9293,7622,2564,7644,2213,6941,6040,9282,714,5293,1827,4590,1267,5694,8673,8711,3290,1667,6431,8274,3944,1514,83,2963,4712,7734,2892,1483,7951,5600,2344,5501,2806,2478,3372,3723,9057,4977,5738,6670,4298,7664,9808,5076,6640,5444,7708,8874,9602,5746,2054,9807,3374,2594,8450,6101,3068,9721,2349,3767,9637,442,166,684,1666,6773,7969,7476,7511,3620,2359,6690,3194,7622,4148,7816,2978,2206,3693,6343,1765,503,7361,5430,6334,495,4580,9903,5703,281,5133,7579,7972,8747,6689,3595,6515,2752,4914,4532,7262,8045,1170,306,519,3835,6333,7335,8082,5372,1314,6510,5818,1963,7057,7860,1505,5714,186,5065,8504,8686,5638,5804,2571,9885,3025,3693,9851,2595,957,9951,6534,5595,5253,224,2972,5323,5131,607,8586,7454,5662,9020,8836,3736,7697,6629,4759,5835,401,4623,8069,7691,5529,5551,4774,7592,4649,4263,8631,5776,4947,3061,6882,6164,2121,5573,2692,2501,6685,4884,6033,5855,5023,1290,7173,4544,7106,6955,644,3081,5689,9380,2136,1184,4404,2892,3989,9467,9506,1973,823,4019,8818,3047,777,7557,6028,6977,7542,5736,22,7593,9363,4444,3846,3107,8666,9626,8074,3118,5355,6603,9740,8198,863,962,8947,1824,5580,7670,3020,9244,4259,269,9266,8519,8225,7515,9836,2102,356,4941,180,3185,1498,2154,6613,78,2676,9183,6397,3780,6382,2680,9934,8369,645,4385,4051,9635,9673,1726,3594,3690,7117,1631,3240,3071,1889,3126,2229,5777,4013,2114,5958,3707,7043,2646,1285,139,7036,3167,5082,2830,9294,4036,9380,4358,8442,4614,4136,1549,5618,2630,9367,9730,9311,2408,1063,9334,9429,5020,7962,5731,1118,8060,7639,7140,2797,7409,1741,1649,5390,9609,4666,5369,2284,4955,9016,3058,7775,8241,4226,3791,6260,4300,1279,4717,5237,4247,7181,8826,2455,7762,9226,9917,3288,6036,182,8397,3853,1891,80,6174,6927,135,1653,7216,8920,5471,4702,4913,2798,263,5630,8276,9013,7573,1149,9263,9871,6274,4973,2890,1135,9847,4869,7768,3877,3146,9915,80,1013,3605,3572,2944,877,9857,992,9919,7000,7194,3561,2578,6871,4049,6337,1969,6436,4320,6681,708,3863,9915,161,3724,406,2486,6522,728,1261,1183,7499,3981,7240,1667,6780,2466,7032,9534,9660,1645,2041,4189,193,9235,8333,8074,2594,3672,2252,455,2294,1744,6279,8877,9675,9064,7830,2273,7763,9433,5408,9224,7023,7829,4763,2681,733,8943,6657,2919,8743,4682,2029,7981,2807,9214,4044,6156,3511,3976,2297,4822,2641,9686,1282,9899,5247,6924,8579,7857,7253,1122,4270,5874,2963,4928,139,2466,4537,3887,5024,2653,2502,1350,3359,3777,9412,7688,4409,4256,6732,6903,3138,6100,3262,7454,4861,3400,3929,2641,8897,238,5322,4491,2491,5565,598,8199,7858,2012,4890,9769,2721,108,6227,2466,7305,8498,8720,2184,6630,7971,555,4596,4431,109,869,722,6571,5570,9090,5364,2380,5561,1300,913,1504,4563,3382,9580,9128,9884,7089,9718,2266,2969,3617,5949,1332,9888,8189,2468,9322,5506,7344,7223,9629,1102,3182,9617,209,2039,2823,8104,9941,6056,2575,5082,2552,1604,9087,4885,693,3301,2674,1298,4166,9984,1883,1616,2489,9408,7988,254,8711,2864,5957,7699,6825,3753,4021,2874,3953,7424,1861,1162,1633,5865,60,535,4655,5619,9948,1039,9553,1952,4265,6534,9370,5519,5531,6171,301,8743,7544,6300,8005,9441,7667,8662,2900,9244,5146,573,242,4719,9858,8630,4414,1405,2546,8138,3600,6421,8900,5145,8885,9332,9655,5281,1903,7324,4094,9541,1400,8337,5312,9425,3684,5655,5429,4858,5449,8690,4322,8417,1807,288,8619,6000,9305,2314,544,283,7816,2442,7064,4773,945,1267,8170,1201,9225,2961,6673,755,451,6159,4521,8688,345,5575,4688,4607,8530,6823,7664,851,7983,2225,1115,5819,894,7194,7923,5811,2621,6774,487,8987,2920,4555,5627,2543,4514,3914,7459,340,4625,3268,6573,1293,7468,1407,6707,1619,1794,4411,3690,1664,7505,2119,2971,6480,6399,3521,9477,389,3676,2008,3962,1187,6808,9242,6719,283,9921,9254,523,1519,2084,2328,2278,7189,8203,6565,1887,3191,2931,9534,7566,2808,7959,3611,3374,9207,9582,4245,1608,1608,6471,3618,6402,7038,1767,5725,2678,3422,1192,6004,1405,3455,7334,2858,6723,2078,52,3775,8249,9576,1646,8858,1173,1282,8548,770,7341,8131,5455,7870,1688,3558,3098,2322,5718,2561,5459,4399,3829,6544,8239,7178,7333,4019,7772,3359,3411,6494,6800,1275,917,8672,3477,7633,5666,2512,7822,9625,8955,4715,3866,6625,5444,5004,9205,9494,4797,3824,6033,7582,2626,2244,3467,9229,627,3154,8952,6097,2493,145,6265,9024,3726,9946,8583,963,183,7021,8423,9352,7309,695,4866,2248,6538,7328,2735,1646,1725,7689,3805,3921,7685,9410,7652,2846,7838,181,3831,2392,9004,4715,3170,2482,9408,7124,620,9358,513,4790,1983,421,1331,1312,9839,9969,3462,7313,1395,1094,9664,2960,6657,4617,8383,7383,2182,6252,3882,3109,4700,9605,3438,2229,4008,7771,8333,1235,6519,2339,1649,9894,4816,9484,1564,4361,2845,5650,8432,6389,2435,6443,4119,4644,7473,6360,8603,4261,9319,8415,6792,9938,8723,2242,1726,9108,3308,548,2187,3323,1991,7787,591,3979,49,2758,6122,809,8230,7564,3152,1175,9593,8226,1430,5572,7070,809,6254,7536,5256,9780,9840,3474,4093,4617,2206,3261,9634,1140,6438,6888,1501,1606,4094,5549,1353,443,6139,3188,5181,1988,6240,1016,662,4551,4840,8929,1448,1295,6169,6454,2280,1074,519,4613,3546,401,3982,61,7217,9754,9582,2642,3249,9778,953,7417,5777,6727,533,4349,8067,1061,633,3890,5047,7377,7042,1861,3039,4824,4922,5887,6681,413,9463,6611,6977,7297,3501,4902,5170,2308,5157,2426,6757,5188,1716,6371,2614,2095,7808,5614,2979,1784,768,7150,8682,3973,3451,3383,3928,6910,6045,6556,71,6142,8828,7531,459,5363,7773,3344,947,8808,9598,3868,6449,1943,2250,7261,9948,397,498,3902,1850,9247,648,9871,6812,6000,2737,2773,8237,1651,1756,3159,4852,8519,9797,3660,6470,2054,1225,1852,7150,6247,7778,2340,3530,1401,8344,581,9066,1424,5239,3295,2768,2861,794,3290,9460,6713,7858,6926,6238,4833,8365,5800,7878,9446,9404,7389,1254,5699,8868,4524,4285,4184,5087,8705,7768,3775,778,939,8444,9354,2635,1609,1736,6085,5930,4189,407,2884,9079,6921,1687,3469,3457,2255,5133,3607,1229,3698,5941,4400,2011,7183,8317,2005,6927,7002,8267,1309,1537,9117,6953,3915,4483,3596,8999,7762,9580,4535,7173,8288,5198,6797,9643,4183,4673,6308,898,2734,6842,4329,6733,965,4292,6460,1774,662,2044,4622,1670,7860,220,7668,1330,834,5446,2708,6003,769,4228,281,9532,4423,6360,6287,6706,1396,6737,1762,9317,696,4944,2719,5688,6051,3856,4854,833,7357,6461,9898,8236,3589,5105,8475,7317,1903,7714,6977,217,2307,5200,964,6075,6364,6261,1544,3935,9435,6418,6110,669,6156,5593,4081,5974,8698,4449,5953,5856,9734,4806,7263,2099,7739,3130,6415,5819,2941,837,1955,8470,1729,9317,6596,8295,4589,4040,2957,5739,2267,115,3985,205,2152,4493,3934,2817,5186,3610,275,2728,6789,7105,616,6475,9849,6115,2787,5284,8509,7279,367,2931,9952,4951,749,5107,8677,6789,5316,7861,668,9328,4820,6841,4652,8904,6258,180,5219,7959,9523,8274,9636,9677,5984,2410,2728,1608,7019,5809,1687,9903,2861,145,3570,3684,3433,7962,8293,8339,5737,6510,7101,7479,1817,5542,8348,897,9210,1535,399,2651,8984,7567,6833,1577,8757,4647,5581,2108,7331,1294,8483,6296,4984,8116,5202,614,1946,9804,9107,3307,5851,5576,8530,2493,632,297,9511,9638,7609,9516,8588,810,5148,6319,9449,385,5616,8599,9603,7346,6122,8746,5166,4959,8820,914,7201,8966,3580,4930,4455,8177,9447,9526,381,1597,9549,3721,7558,2352,4857,3920,3971,9714,9858,5408,9621,3201,8929,5222,3900,2390,6903,4511,5481,4086,2648,2098,504,2400,1868,8221,3487,1374,4814,6545,7396,1964,2976,4267,83,234,1109,118,4448,3791,2710,4605,5163,4905,5945,4526,4439,6447,4013,7806,6701,4167,1433,8340,3800,1028,5191,8732,6257,8058,7073,5286,5464,655,11,2258,2703,1680,4333,5999,9415,4637,5104,6562,3782,3319,8953,2226,9359,9196,7140,8553,95,3748,8197,2844,307,6984,2007,5254,2365,6768,5632,2159,9644,6931,8751,3847,1869,5987,8404,2495,4345,5600,7598,8437,6326,2620,1558,465,1694,4250,7917,6624,808,5376,1168,5186,5301,48,6374,1975,3831,8704,622,7730,5738,2639,2680,4880,3539,6775,9525,4108,6100,1168,6049,3774,6255,7700,374,7146,2288,3546,892,8276,8568,2147,8207,5009,2906,4426,862,5920,8852,7681,5710,4008,5711,1123,8147,3424,7464,2094,5002,846,9508,5032,7659,9378,931,660,5594,9827,9852,1110,889,1424,14,9870,768,7274,7806,9989,7335,4088,8438,312,6551,9640,7970,3386,8637,8809,8709,9715,5471,7446,1103,7833,6944,4982,3050,2511,3377,104,1774,7629,8394,9722,9578,8138,1818,3088,7710,9266,8792,6656,1944,248,4042,8929,5025,9898,8430,7018,6804,7991,5183,5015,251,876,596,7114,919,2133,7196,854,3819,9736,4225,7211,8888,3719,3718,858,180,8414,8434,7142,7846,236,4637,7029,7343,7559,9669,8663,6126,322,9633,5086,3955,7042,8093,2517,6149,1279,7442,7269,8666,9440,2571,5242,1908,5510,1654,7981,6518,6521,5470,6424,2611,7340,8495,1953,5566,9472,3598,2416,75,9912,61,3370,4795,5991,5373,3207,6498,3916,4955,3297,2295,3864,5700,6317,5518,2379,3052,1212,486,4824,6342,6930,7472,2737,1098,9077,9047,4522,7872,9509,3395,3634,4918,3289,2475,9410,6906,2890,1344,7561,4750,493,2957,5043,9869,4895,7984,3778,9880,2731,9669,7841,901,2289,8437,5586,2443,5218,9345,8665,6804,1352,4372,3271,4294,948,8862,698,6808,5306,8341,9275,7246,6809,8758,3144,4070,4635,9707,2016,1899,2681,7900,2772,929,6450,2642,306,2602,2702,912,7923,858,2343,5045,6372,2665,7906,1269,3677,9081,519,9982,3888,4868,8497,6304,2454,2547,3761,9200,2523,6283,589,1708,5882,3899,1798,9767,2109,171,7080,676,5544,5242,4105,942,9940,7613,31,5453,9660,2154,3807,4901,8735,4943,1080,1244,5902,7091,8095,6757,3927,6516,7182,5239,2815,7028,876,7216,3147,1826,7574,1585,1015,9665,7448,5311,1188,3436,219,466,6623,3128,145,5937,3019,641,3293,7205,3124,4856,3706,7996,6418,1405,1090,324,9406,4461,3026,4136,3440,6958,9791,5533,8166,4576,4143,2055,8511,219,7527,817,5095,5112,1999,4762,5568,9182,7555,7489,9494,9519,8020,1482,1792,5164,1334,9830,9113,6738,2256,4266,6487,2979,3804,1452,7886,1769,7175,9819,6426,7825,8115,6356,5577,7093,6411,1381,4511,1108,4613,907,5219,2643,5755,7556,7373,3260,8026,3300,9118,2127,3661,1159,7289,3383,4961,9316,7493,2475,3112,8918,3813,8962,8501,8946,3639,4643,1987,8951,9101,8263,1222,3119,1583,8787,8487,1799,2818,1092,1271,5383,9637,5550,3960,6423,5733,6994,1564,382,5936,4365,3178,207,1460,4796,3392,5297,8107,3964,8008,7605,7587,113,29,7497,2389,7893,4188,2143,4695,257,2961,3876,9367,9047,2757,2483,826,8614,7584,5375,8137,2747,6311,265,9477,8096,4443,9141,4118,8758,1260,5316,3695,6814,6165,995,608,1321,3776,9655,533,9975,6569,6000,7601,5671,5477,8799,5543,4022,9037,8584,4306,4581,3179,9137,52,9874,7614,265,2076,4581,8798,2248,1079,6496,9712,5385,4355,5727,16,1677,2485,449,3437,3397,6237,5148,8074,2953,3683,762,5002,9022,6955,3714,9507,3578,7855,8180,8307,2025,7557,9046,248,5772,8236,7869,9097,6685,9951,1959,7020,2024,936,8894,7586,1176,2246,8163,4949,8835,5970,472,9543,1388,2624,6452,2163,5959,236,8518,6276,9743,7162,1933,2642,1983,3926,6632,1938,814,5449,2128,3165,8396,2193,493,5845,940,7905,6874,5407,1646,1504,423,4587,551,6290,8051,1106,9969,6601,8114,8016,3466,4251,541,6258,9552,242,1943,7080,1497,2101,9668,763,5873,3073,4530,4466,3271,4342,5265,3596,6319,1055,1781,4572,3049,4216,5511,4956,8775,403,2843,6467,8547,9638,251,7617,6005,7570,2260,3278,2075,8178,6923,1473,2522,5833,3507,8371,4729,1271,5915,2962,7246,9562,8202,5110,77,6624,2700,6139,9993,527,1165,312,5677,3109,4301,8952,4454,3033,8625,9268,4940,1173,6919,429,4368,4578,7835,3279,1316,8495,1672,5771,9137,3711,4808,2072,4443,8292,2370,4737,6133,6381,6833,9051,2675,1066,6188,4160,4365,7639,5788,2263,642,7689,2202,393,4155,9477,73,3932,6264,2229,1055,4602,229,7493,6461,5120,2967,4357,7958,3770,1836,8310,9631,1605,5253,2846,2443,5212,8115,8452,4215,8471,1212,3549,3412,6234,7158,9818,8135,9055,5647,5564,2112,1729,2443,997,3442,1331,8544,816,1922,9056,2704,6939,6276,1979,3242,9601,7052,1090,2372,1222,6565,8255,5281,8557,8641,7315,505,8764,5234,5071,3569,1565,5497,1976,4931,6202,38,998,4344,7886,5376,7938,7586,7421,9274,9635,7585,43,1848,1036,4923,5838,6144,1581,4632,1567,4702,358,4321,2648,8569,927,7292,9096,171,8476,5050,2698,2312,9840,684,2990,9283,2540,9050,8795,6250,2861,1451,452,818,9128,7930,9920,759,9664,4981,1322,6060,454,1975,2924,1100,9957,8492,7980,6697,5840,7826,6037,4711,9553,192,721,7448,1667,9267,1666,378,5961,5536,5112,186,3848,4151,4009,1338,9220,6946,1756,9508,4812,2639,8286,4319,36,5902,6842,3176,5975,5482,3306,5843,9694,2405,4976,3072,8139,3945,512,9442,6180,548,933,3007,202,3154,4152,470,1898,7441,1488,9716,7241,3179,4609,3300,8941,6915,823,2791,8170,7195,2482,7036,1133,8154,6309,8795,3417,2772,9290,6114,8144,8080,4796,6436,7858,4416,6753,9726,5394,282,1951,1293,6446,2007,2839,3207,3098,4795,7945,6725,6881,1887,5112,2434,3357,5981,326,3223,2688,4951,2094,4294,7085,2633,1338,3129,5034,498,9929,8667,3924,7220,906,5892,5555,4529,4201,2774,9721,4049,5630,7206,6387,1286,2161,8475,3964,1304,6947,156,2547,8866,4685,5638,7465,1119,4754,7740,7283,7394,5002,4135,9649,7354,4437,540,5788,551,3197,2458,7667,7507,4693,8317,9604,5609,5988,1253,7932,4016,3635,2857,4532,8591,1169,7496,6158,1894,3523,8077,3564,4554,6606,3605,9609,1465,9188,8002,3508,5449,1922,8063,4842,8401,9637,870,8324,3584,7876,6787,5150,1552,8133,1182,3787,6254,90,4368,2998,4237,4780,2585,256,2972,5303,6665,1465,4940,3453,7641,4054,4970,8863,7626,1345,8761,1274,3723,494,1748,9047,436,5784,2450,4082,6833,8742,1923,727,71,7310,6574,8309,6356,4657,8357,2446,7331,6063,3246,2838,785,8299,626,4749,2792,9966,9179,6238,5027,5375,4358,958,5329,1884,3206,7180,3441,5325,5620,4858,7265,22,5525,4825,8012,7448,3539,746,2397,4191,6274,5600,3835,6858,2173,5736,6117,2777,917,2407,9290,3231,5291,3608,7625,3213,8998,8427,4680,840,461,1644,2258,433,2953,6619,7551,2961,608,9730,1200,3675,8672,1225,3563,3066,36,9778,1801,4808,8779,341,9659,9477,8677,1423,1836,8615,6083,466,6264,5623,6325,9802,5898,7463,456,2453,8754,4824,5309,1350,6347,7243,1244,7538,6584,5039,3186,3242,9139,2464,1251,3495,7519,8387,1815,7779,4937,2244,3833,3337,3057,6090,3417,7321,7587,9840,1298,1474,1302,5610,4358,6804,2045,1955,8683,7980,1324,2459,7806,9089,4306,2029,7390,101,3004,2433,6568,8738,7789,2417,918,251,6815,4097,2717,4787,4350,3440,457,7477,6341,3880,1110,6755,4471,4168,8311,5174,3431,1875,2931,8592,327,2448,7633,4470,8099,4274,7025,1369,9546,1679,302,7620,1475,8643,7897,5463,9869,5172,9974,1692,6126,4067,5180,2531,3030,325,2701,3030,7619,6213,9684,9113,2389,1469,228,8525,9021,541,4064,6399,3879,4415,2004,8514,7356,3521,1860,1919,7933,8082,3475,4069,9109,4186,8892,5074,58,5469,54,9436,2198,5921,301,7998,9508,3778,2997,2570,8355,7452,5260,7437,3781,8942,9457,7550,9759,9485,3680,7089,7785,3664,5676,1292,444,6480,2379,9435,6935,3973,9998,1890,1198,7729,2135,4141,1291,2347,2445,9216,7734,4794,8488,3778,2190,9581,7716,3714,6001,4006,5338,3484,2327,6752,3820,204,3001,1257,7332,9425,3506,4279,2485,8009,1370,6150,4074,4848,3436,137,4135,3170,102,7766,5903,4326,2163,8397,5807,9664,2267,310,2223,8217,2019,6121,1362,8497,3489,8770,5668,1397,412,201,4257,945,3270,6895,8884,8287,2187,9101,1706,6835,9753,1739,5549,9457,5644,1028,8006,8460,7185,3375,5741,3312,882,1774,540,6436,2493,5601,9712,3100,5324,8954,6528,1004,8634,5620,3996,4351,229,5325,971,6096,2983,5628,2341,2014,3095,4513,5415,6827,8593,1486,2586,3983,9997,4485,342,3274,1005,5048,5875,1222,1833,9923,8303,7210,5048,9899,2717,9908,9051,4451,856,5057,73,6364,291,259,4798,5701,8477,6348,3132,2188,6039,5569,1054,1375,451,439,6812,1178,3583,2121,3945,3104,2714,9820,577,5465,1084,1627,313,6477,8184,9719,2702,5655,912,4772,5539,8330,2556,9229,162,4794,7742,7253,1017,141,2134,1690,7910,4471,2741,5105,1856,7809,9844,8922,3187,2648,1738,5185,3658,3568,8874,3303,4852,5478,3273,5573,5832,8433,9536,731,2918,9451,9558,6099,4078,9531,4741,7408,7311,2574,1129,5509,4462,2162,6848,57,7307,3037,7373,76,7435,616,982,5423,466,5241,8913,8740,5820,9703,9892,9239,3228,1514,6174,8127,3339,379,7383,205,525,3504,750,3151,8374,5491,109,7438,296,835,1101,7850,5002,3951,5538,1027,9017,3441,4747,926,3550,915,681,9079,3061,9176,2963,9661,8086,8797,4921,9126,254,6880,9424,7478,20,4359,9086,3185,3070,842,6646,2252,276,5246,7764,4713,4995,9386,9250,9625,8447,191,369,409,3893,6170,5594,7378,5515,9766,9113,3700,7448,1711,735,1536,1323,3464,1213,9697,5074,5910,9168,8637,1595,1320,1403,7527,7130,4837,5442,1617,4595,3573,6540,8541,2443,5029,235,8082,9563,6608,7141,116,1167,3245,2721,4447,1670,3900,8433,369,3858,904,9575,9393,9737,8146,8323,5989,6838,1070,2553,7505,2578,1028,844,4403,4440,2199,4620,6027,2707,6442,1905,4841,808,7508,1438,7013,3407,6871,2770,9569,2834,4046,3129,2169,5753,7231,5881,6030,4091,4809,777,4762,7212,5072,8222,5183,2950,5155,6716,2303,7401,3470,4955,4442,3104,7906,5437,2134,9780,7618,1180,9803,1036,5882,534,5775,1110,8664,6991,7341,8990,1904,2800,6253,2672,8047,7247,2238,6469,4972,2071,3484,4422,3175,7184,5193,1137,5848,7358,4613,3372,6694,5629,5205,235,5750,7223,8586,8575,5768,6500,5732,3094,454,5191,5952,5920,6648,5791,1189,4884,9576,1994,2218,8359,6290,1336,8150,195,6742,9310,2175,6576,119,473,100,5798,511,5711,3040,5361,907,877,3192,6213,3517,7831,7180,4731,8470,1138,3035,7566,5898,7945,9637,7506,7470,971,2088,6633,7772,8102,9677,5142,9623,5568,1086,7569,6120,856,6064,418,8216,3437,3247,6549,9733,3672,5848,1091,3795,4376,989,6435,5424,5773,6313,6631,860,3109,6054,3253,183,5106,3567,5601,4074,7857,1805,8246,2070,5444,405,1652,2726,6385,1897,3412,5249,2553,9681,2535,2975,9219,9663,6551,2562,9974,8700,2140,9160,945,352,665,4605,2618,789,198,1064,7583,3096,281,5519,3360,1650,1751,3816,3749,9136,5040,3174,5933,2737,3749,4321,1760,9128,7133,980,1903,723,6310,9714,4307,4407,8887,2825,7429,4156,1230,9773,9999,891,8231,4738,1456,9482,2237,7019,8124,5286,5283,2507,6069,125,5137,7870,7846,4935,1829,9333,4135,8196,9855,1585,4344,1958,3389,3914,6298,4686,7186,4775,4119,3829,3517,2584,9533,9971,5475,5317,3424,3986,8954,4914,5190,7909,5105,7376,122,8765,4939,5361,0,4636,3862,841,9475,6324,6988,2324,4464,1697,767,6147,2910,9171,790,7472,2067,4347,5655,5847,8970,7187,8938,6711,2529,5977,6675,1469,4363,99,8749,837,9578,9517,4024,8467,3629,2825,2264,2308,7542,41,8382,21,2920,9420,9032,6939,3064,368,3011,8241,6621,7850,2387,9239,4735,8765,8761,3336,4612,5514,4704,8719,6890,4413,7907,1536,2781,8119,2238,9275,4107,5978,8485,7613,6524,6206,759,1718,2080,739,7751,4305,8003,4141,7126,2142,8298,4932,8531,9913,9965,1421,1062,8279,9539,6579,1976,8687,4916,2234,2443,3025,1073,874,1102,5283,3321,1236,6062,5787,980,6850,9019,3047,1588,6603,48,5858,5304,4136,2279,5378,6066,1078,4427,2755,5388,248,3049,2436,3616,1414,804,756,6203,4366,7988,2175,6100,1020,9550,6139,515,4820,5531,1863,6482,6310,6793,6368,8605,8813,2497,964,9133,66,1258,9970,217,5999,5406,7350,9176,9268,1480,6137,7039,8964,8100,1816,3140,8820,3764,8665,8794,9963,4658,9855,9237,9076,2552,757,9149,3991,5838,8502,8603,5832,5397,6125,1596,4528,522,8284,6017,9417,1300,477,808,6931,2500,9364,8469,4601,781,4906,4177,5793,5531,3934,2492,1651,5530,9533,8157,7826,105,3367,5903,7166,6173,8723,2470,7037,4795,6267,5944,7051,4873,2231,6129,5010,1866,7465,3356,3097,1165,288,7518,2547,7627,4430,7073,1006,8729,7112,5152,9630,6188,5968,1599,5201,2046,5873,3310,5127,9307,5769,3320,8617,1234,1631,2356,2358,4682,7821,7983,1180,1884,2843,8307,2195,9,4114,477,7887,3117,1921,9197,6346,9710,5820,5179,5195,5463,3940,3903,3932,1058,7463,1270,9557,776,3778,8766,3708,6077,8540,4196,6630,5880,4787,3197,905,7035,1554,7940,249,1798,3246,7779,7098,3574,1283,1218,7931,2223,3821,1741,3300,774,2493,9536,3174,7516,5639,2725,3330,6488,4665,6670,3650,5853,7224,1408,2764,4738,7886,4285,3255,7508,8858,9075,4299,3995,5900,9,2558,1264,9113,214,2152,861,2342,4035,945,7191,2167,1087,7493,2632,6644,738,681,3047,7618,4344,834,3551,8221,6318,4868,1005,8766,8081,764,4102,7280,6101,9299,9278,92,4630,810,1664,6440,9287,6215,6753,6092,5370,1033,9895,8929,4428,2710,1518,1124,4526,4452,5534,8212,1483,9804,3957,2574,699,59,802,7862,1624,7088,5667,6208,7461,2667,8587,2063,6240,9851,4646,7886,601,7931,2842,1434,1025,8892,9631,1444,6149,3518,2764,1599,8774,5831,6478,31,5175,9942,9704,2835,5434,5551,5067,3077,4051,1993,1476,5896,6648,9709,1367,4331,4050,2765,6659,2067,2219,287,9697,6277,9021,5275,2072,3790,7261,6899,9797,3194,1089,8874,7585,4774,5697,7347,5827,6230,2663,9509,828,3771,3797,519,2200,745,2837,8453,9893,8058,4915,5183,133,1069,7753,6597,4454,9109,4040,3634,502,6009,288,1740,5236,9699,7229,5663,3300,5418,816,9212,6660,2311,90,309,251,3460,3203,4748,9261,5475,5928,2542,6072,5495,8153,3892,6579,8774,1890,3027,3840,5531,6986,6419,4057,5827,3935,8237,2576,7380,3852,2516,8463,2384,87,4397,8013,5965,1362,8401,1138,1923,8044,8054,5255,3465,9749,6236,845,8788,977,2880,8894,4095,5142,7815,8013,7256,6419,3852,3222,2337,66,1143,1052,710,7277,3138,6274,5931,3296,1802,6762,6605,4252,7296,915,6746,9783,9556,7251,3875,4447,8981,8810,5929,7471,5188,6328,7515,3300,3542,2918,4328,5579,3986,4650,6802,2726,3517,1012,1257,3329,5906,8567,6024,8962,6712,8419,4642,5753,1488,9683,8169,3893,8269,6360,742,4084,4595,4876,5820,1850,143,8507,4227,7151,6820,1036,5732,8639,6477,2754,4577,1638,2969,7832,1461,5140,9612,139,3274,4893,4433,4629,1622,3652,3170,5496,5116,7541,5514,7320,3409,9397,5511,4546,798,1960,9527,8522,7629,2215,3357,9641,3319,9167,721,8935,615,3293,3300,795,9834,6036,8509,634,2862,2250,5755,1185,4165,130,2251,3156,3421,2786,6620,3368,4393,9348,2140,7709,9595,1082,4884,3729,3909,3189,8107,9098,541,5233,56,7512,1281,6521,9928,8387,1898,7902,2460,8329,1194,868,6010,5529,4726,154,2881,8693,9862,8256,6275,2654,8282,4464,4824,8778,209,9907,5158,9337,5721,5459,7532,6415,1422,661,4307,3618,3776,8238,8995,866,544,3150,6094,4068,8718,8979,1578,4969,1392,1835,842,315,1431,4008,8908,5776,2845,2676,3220,2487,9900,2082,7406,8362,5894,1211,8837,7674,4172,2660,601,5523,2816,6065,6969,5958,6099,6671,2766,7549,6866,3736,3018,3215,9106,3351,4396,6680,4167,7345,2492,9947,4675,1330,6069,875,1010,6757,7282,7372,5157,3909,9573,5691,1751,6563,2619,3181,5090,516,8915,2601,332,2578,8077,7172,284,4797,8508,803,4982,7456,6974,2869,6610,966,2119,696,8551,2706,8000,5124,7680,8430,9700,980,5803,1592,4095,7641,5802,1278,4138,3052,5618,8630,1853,3887,2536,366,5178,3267,8467,1188,2003,1080,2300,4422,2749,7985,7407,818,9058,5046,5233,6679,9280,153,3775,9655,4524,5557,2331,5834,3155,5918,7018,1419,1463,749,2256,2218,4861,6840,6342,1479,2573,6426,9100,4304,5708,1637,6404,9004,7042,4917,4272,4480,6453,7769,8280,510,3958,1318,87,607,2740,6324,8736,2076,3999,9553,2787,5821,9366,9073,2179,5938,4618,3846,9884,4485,8549,9012,1250,2648,4597,8298,2755,1098,8708,2061,9851,2870,3068,129,9105,7406,6753,4370,1655,8152,2034,8635,1646,7907,7312,3129,6943,4820,2641,8723,1266,3492,879,7094,1499,3808,627,9321,8091,6239,4454,2845,8757,69,6228,2184,324,6138,9602,1035,2319,259,8035,7524,6187,5704,4307,1444,398,5754,1362,500,4178,4115,9857,3939,6557,6172,4119,2227,2570,8753,1784,9569,3082,2767,2288,1886,682,9665,5943,9836,5822,7303,1094,4241,3171,6162,5493,6377,6991,5547,7728,2080,4371,6769,8946,587,8911,203,6474,8883,9083,4488,9052,7740,824,7469,5427,1459,4960,9597,1743,8140,7633,1195,3720,7421,2216,1598,6483,973,1742,5031,2935,6036,1368,6133,9450,788,3779,208,3482,2642,9310,8816,8701,2552,8940,3286,346,4522,5614,9513,8236,2325,1547,4018,5825,4378,2476,2821,5914,1976,3046,9357,1279,29,1003,3679,9794,4329,9129,1415,4280,7024,1896,4779,985,7033,3232,7011,894,9264,6154,276,707,8674,6014,5102,5478,5668,6921,6167,1232,9547,9526,2790,1373,6620,2280,1518,6138,7578,3221,310,1827,8951,418,1990,9232,7062,4503,1333,902,709,2265,8355,9639,7354,6852,1522,2066,9359,6967,9341,4222,1880,3901,466,4312,4608,3624,980,4598,9457,2574,7589,4318,921,7419,1636,1162,9457,637,2353,5986,943,139,234,3817,3542,5091,2800,9367,7562,725,1527,9972,871,4172,5534,5616,832,3697,4678,2690,6050,1966,8126,7696,603,358,2838,9584,9700,7681,107,1537,3472,310,3052,7470,6461,9450,1906,635,3765,5246,2897,9347,6833,8324,64,4025,2219,987,5482,3291,2120,5153,2972,4758,4873,7153,8738,7227,7886,9804,9871,6428,4795,4369,7854,1609,4680,8359,5998,2018,2601,2838,469,753,8265,206,8830,2307,9643,5584,791,853,7134,7010,3428,8662,9676,2820,9496,9019,521,2151,8795,9193,681,4886,8748,4448,9689,4948,8231,3407,3277,1048,352,4840,4770,1626,5106,7215,3441,6852,8553,8974,664,4254,1867,6116,2634,590,3585,2129,2947,5932,2284,6393,5584,3067,4602,3207,5708,9410,4304,7063,7221,4154,6942,6981,5479,7323,2317,6476,6978,4026,4804,3474,6812,2213,2102,3368,1715,7185,5644,5164,3077,6220,9659,172,663,8376,8910,7296,7568,7729,5683,3048,4890,6881,3565,844,9009,5070,8639,6957,8865,4253,2650,4232,1682,3251,1467,4760,260,7287,507,6828,6115,980,1446,9799,2244,4969,2237,5418,4223,9687,1461,1678,6185,3768,4303,8219,4764,4450,6618,5702,1662,2155,8352,8243,6932,9555,4095,8961,591,5818,87,5929,4216,4502,4971,2780,5766,8360,1614,9522,2903,2601,3735,4530,1125,2697,8269,6701,2999,4486,801,2912,5589,8200,7913,7174,4350,968,2283,9194,7625,8334,3540,4051,405,2643,6313,3392,2805,4809,4305,3910,7748,6032,6680,5427,1594,1956,9748,2618,6534,9608,2545,1488,8444,658,1201,6615,5916,1694,7700,3370,756,1923,8746,4091,6791,5316,6104,8981,5222,5595,7836,7583,9431,5460,3590,9780,2182,4012,7484,4565,5542,3558,1816,9129,522,1819,7217,8177,8313,5532,3341,9792,1359,2103,8786,5949,5679,7754,5769,6869,5997,8459,3236,530,1183,4689,3070,6332,3354,2764,6506,7984,1570,4982,9130,6821,9781,9182,4608,8144,4148,2929,726,8200,1656,796,106,5095,1406,1782,583,4998,7249,5571,1176,4059,9436,7098,2736,4103,3583,4585,314,3988,4556,1140,167,560,7584,9020,2518,5799,279,2144,38,1735,7853,1574,2783,8476,5382,9568,9690,4472,8162,6812,2834,2254,6923,7026,8356,5497,7893,8456,1293,2141,2743,1581,2118,1210,4874,914,2786,5295,6306,3186,6730,9730,9717,8717,4951,1089,8783,9182,8065,1888,6811,415,2381,6110,7446,8298,4582,9640,5878,9676,4958,5217,3096,1516,9693,9546,2245,9100,4916,6077,6795,5706,8325,4621,1980,1827,3956,3503,9626,2678,3157,5871,8773,1576,5283,2865,1530,241,3103,269,2803,4658,3684,9158,5955,6096,3287,1167,1448,2263,2145,9120,7781,4270,4509,1512,3239,8875,342,2398,2530,124,4369,8849,7804,5867,2042,6249,7718,496,5789,364,5304,4956,1421,4559,2959,4697,5836,7815,7914,1128,4698,787,2093,55,2534,3417,9979,768,6429,9792,8304,3518,2705,6489,6006,7828,582,3111,3304,8335,4443,415,5495,8989,2560,9187,4741,6784,644,4885,8471,3018,8928,6746,5466,8042,849,877,3575,7099,9232,4895,7654,8529,4793,7322,6177,7684,7615,110,3938,9382,7476,4984,8618,8950,2288,4577,3518,5341,9684,9088,7887,4739,4399,4510,4894,6142,8732,9983,965,8090,5382,5570,995,4814,6841,7668,8167,252,320,6065,7398,686,4874,3077,4830,8459,3336,4094,7803,4377,309,6149,5638,3995,5074,5592,8221,2536,545,5369,6536,532,9264,7940,7051,5804,7732,4547,6955,237,4325,848,7786,9214,4434,4497,7843,1253,3325,7148,6894,8050,6522,1590,3163,9163,3172,1003,1867,6113,4632,8003,3450,2092,9645,8968,4021,2392,6434,4928,2596,7109,8890,5607,7417,6369,7760,7088,9611,4507,9684,223,3144,314,6443,8001,69,485,4099,3969,8082,2644,9244,3082,2240,108,8431,3687,9272,7667,6260,7227,1937,8568,3860,5610,1554,3569,1137,3077,4601,817,7039,5587,8023,1639,7988,7839,3992,8890,35,1365,4291,3571,4615,8178,3296,9443,9470,5521,952,4239,6151,9659,565,2823,9313,8540,4487,3037,3935,6037,8390,5826,2233,2481,9526,9692,6434,5305,8608,2671,5212,968,7255,4032,9304,1506,6910,2824,9715,3304,3955,1983,5801,5122,5512,6617,6606,4379,8150,338,3868,3646,7834,4528,7347,3980,7770,5053,4564,4284,5332,2038,9618,2285,649,5599,3986,3737,9452,2352,9929,2988,8854,7915,9818,8818,8651,7878,8787,9635,9467,8426,1818,8029,9530,6240,6245,8998,2086,6429,4846,3776,1214,5300,819,5806,7412,637,366,3525,1645,3135,2113,3342,1305,8462,1955,3125,2985,5475,1876,6770,4889,8467,1018,7183,3510,2449,9026,5287,2816,2013,423,4176,5233,1519,7409,3573,9776,4342,1637,1230,8700,365,5097,9145,6378,5188,8263,7,3451,5901,5514,6979,8818,570,5394,9806,3230,8354,7497,9480,3126,4802,8917,6789,8343,7625,6347,8370,1629,7403,8843,8453,8288,3040,3187,2082,3796,7680,7598,7627,3591,4362,6368,2339,623,6241,8707,9373,2128,5176,7671,6130,2730,3071,6656,3907,5171,8604,8300,2355,4071,4752,6879,3566,5567,4978,2964,174,6604,8953,1199,8682,3749,6285,4260,2196,1291,5824,1353,849,1263,842,977,1628,4853,7038,1647,3522,6055,6469,1650,7047,9446,8665,7568,1846,535,943,1773,1622,1269,4936,4046,5945,6338,2804,1832,1713,9940,1818,6615,4747,8348,5529,638,6154,7662,4674,4878,1972,7467,5144,773,2515,3996,6860,735,5101,9597,7267,7041,9224,3177,1746,8182,9172,8108,3935,381,4647,8101,2597,4717,3788,1747,254,6893,6667,2558,3642,9601,2213,3317,9922,9481,9107,1302,7056,7118,6577,7558,3163,3979,7430,5255,9549,2131,7533,797,9997,2280,9700,7262,1253,4213,8025,5165,2270,3282,102,4227,4126,9079,7788,2429,3936,6150,9736,4107,4364,4151,2053,4972,9528,6682,5586,1180,459,3768,6349,5382,7880,5478,3751,4561,9649,5015,3123,1442,7253,3281,8659,9629,1518,8441,3867,2368,1314,3586,1823,1609,8872,7453,3122,5123,9294,2811,8096,110,9849,218,6453,3908,6654,8388,3175,9732,6868,1320,1805,3981,3196,9599,6443,3016,2559,4173,1056,9056,9521,6046,6589,9712,8876,5779,8609,6971,5279,3523,9428,2708,9948,594,5742,5640,9408,739,3975,7961,1761,7268,7935,2866,4135,602,4791,5917,110,8937,7819,3279,1561,1722,6269,9615,5408,8398,8743,1868,9750,310,4399,7917,4751,7122,3875,7042,3890,8182,221,9235,8933,2042,3251,8367,5010,9722,9418,8719,3253,6533,4189,775,7523,6049,434,4918,3839,8280,4672,6531,6305,4215,5907,8517,7837,2,3622,3576,444,5697,6710,8929,1665,1630,4995,4085,1433,9170,6029,5968,2805,9513,9639,3824,5786,3116,4160,5858,8243,7637,4592,7300,9267,7243,5618,588,4527,1204,6044,2185,7646,9329,1775,8565,4094,3828,3052,5178,1498,438,1166,8877,446,2712,3842,5679,8029,1408,4130,608,9978,5333,6298,4104,7545,5564,6479,7539,7668,4581,3012,9493,1387,823,118,8766,8058,7012,5534,8899,5302,5101,5663,5756,2675,895,2573,1125,7032,7741,8882,5247,406,3389,9881,8217,1818,4704,5624,8606,3189,5797,7712,1358,598,7009,9829,7850,1058,617,6774,5824,8395,733,7695,9634,8425,3000,3585,6563,2539,5222,1994,9442,4293,465,5943,4321,3666,4219,7598,6422,6939,702,9404,577,9770,2440,3872,7840,4254,3210,8212,9754,9041,1084,1519,4707,2380,5043,6226,1978,5034,4497,5692,8182,9057,9285,4427,9442,2800,2091,3365,171,5008,5756,8823,247,9363,5572,4950,528,750,4080,4612,4695,7232,2655,1217,4544,9082,5800,2228,7468,1391,6777,1217,4567,7381,1433,7837,8057,8229,6170,5033,5156,8271,4360,4786,5246,81,9039,6,5867,1493,7339,9860,2517,8229,3872,3875,9547,2813,2430,8366,7278,1167,4440,8759,4887,4010,4471,8452,2374,3642,121,2895,9712,7909,1320,750,1772,4784,451,1656,253,673,4750,2092,6233,159,5401,9591,2338,1631,6885,2667,9332,1873,542,8835,5604,9379,297,9067,3553,6142,9122,3319,4695,2886,2978,8036,9618,5653,2863,7604,4285,9743,5478,4315,2133,5590,9014,9758,1009,1594,2261,6520,9337,4510,3837,8973,2267,9105,7350,5023,7204,588,1171,131,2694,5155,1098,8673,4996,7325,6679,7607,1109,1069,183,7643,7235,8859,4270,3363,805,9992,4338,4343,957,3662,6196,5083,1987,6255,7188,2007,9856,156,1414,5061,2484,2288,3397,5194,3811,4146,43,5879,9690,8772,4564,7358,9162,2386,9157,7242,3449,9642,4898,2827,2434,2686,2444,4286,3223,6498,7445,5386,1918,4570,8290,6607,0,6416,3553,9161,4492,4932,8618,2412,549,8694,9265,5664,607,8909,898,6496,3772,8757,8787,9848,8774,8351,6243,8901,1471,6137,7432,6907,6725,1136,5555,5081,6509,9290,2379,6647,299,428,3945,7218,8388,1178,8191,1177,318,9719,7443,9920,2546,8565,3040,5694,5499,6033,3104,266,1704,953,868,9874,124,6173,8490,4446,9133,305,6096,6506,4079,9930,5249,6378,589,3090,6813,6790,7727,7828,1230,8856,7793,8719,9130,6826,5998,3827,1033,7827,1625,6350,4308,1094,4718,5652,5403,5794,2453,7221,5799,30,953,7828,5856,2385,8706,9654,6624,5374,79,6061,8183,502,9423,6000,8595,1868,2189,7144,5816,2063,7613,119,5132,1215,2639,756,6816,3941,7042,8787,8860,4702,173,5059,9291,9665,1955,9749,2734,606,3381,3769,1679,64,2789,6099,5013,4914,3593,2822,8865,8575,8543,5421,9370,7926,9034,6417,1172,4214,9621,8426,7051,4568,2215,261,4450,2766,5806,9461,9450,5769,3601,1336,4804,8347,3601,2952,5822,6985,3724,2488,6076,9873,9737,784,2556,2603,1353,9991,7497,4022,1727,8691,1167,25,8742,438,1370,8195,9876,5878,1257,4980,630,8763,4979,7904,1899,6587,2431,5045,8463,9968,2040,7495,4841,941,5507,8330,91,8724,3214,3165,9981,8029,538,627,3245,6732,9302,7655,9069,4096,3688,7621,111,4607,9492,4575,1558,9598,4556,6744,6097,8783,697,9752,7522,8832,4970,9123,8557,5545,1853,5567,2276,5738,5933,9293,4393,7467,691,7880,2982,7803,4409,6972,8953,5357,819,6335,944,9803,1652,4713,9537,6545,1027,8208,9047,5956,6383,3918,121,2441,7671,907,3079,7659,1284,2344,5847,6072,746,8458,3007,2326,8473,9639,8705,7437,3570,1866,1199,3321,5793,8343,5868,1226,6907,1930,2987,3186,6781,1804,25,4268,7425,5078,1937,4153,9986,7633,7180,6538,3774,6389,1498,539,2992,7581,5065,5208,130,1379,2568,3051,8394,8375,294,5734,4588,8311,6064,6301,6249,3770,8978,1966,9744,4196,2430,1800,9507,8390,7621,6380,6857,473,4418,652,6135,2964,815,6668,3403,730,2968,140,7797,194,6017,5435,5064,3628,6883,4101,516,3080,6801,3698,3302,5208,1543,8831,6948,9158,9274,1071,1176,1509,2041,2364,3121,6934,3543,612,155,7696,4956,1535,545,3061,6493,1003,7239,1361,9535,5987,4885,708,6880,1193,7997,9246,4627,777,9228,4760,9710,9358,9869,5819,3230,4000,3085,690,7411,745,5121,1677,2558,9570,8672,9849,8208,6562,347,5426,3930,204,1558,4959,8451,9792,1597,7783,8344,3562,5346,28,6797,8406,8947,3182,7216,9070,3768,2427,5378,9440,2100,3179,6281,9283,270,8916,5978,5864,2910,4221,4023,60,1290,8929,8370,3212,7383,563,409,5217,9540,9580,9556,4177,8721,4394,1079,8070,370,5512,2347,2854,9183,5192,1809,1969,5632,4841,651,5459,3402,2966,5556,9654,5206,4017,4617,4515,7432,4826,254,6692,7370,579,268,1623,4683,5912,3698,1500,9926,5274,4837,3071,6032,2580,9232,5685,4308,7913,9420,2631,336,9989,2763,7773,544,5199,6000,3942,1743,5753,1025,6101,4144,4310,3542,3679,8214,4800,7447,4050,1768,127,4075,8206,4734,908,3927,9428,3107,2212,2377,4603,174,6798,9828,852,2145,4677,1161,1021,1021,5682,213,6362,7419,2722,8295,7483,7466,8066,684,8876,1994,4147,3963,4830,6544,5505,6336,9601,8145,2182,5364,1837,3199,7195,8874,6831,5962,622,601,8714,5880,8861,4830,8534,1594,6332,7611,8398,9369,1935,5677,8719,4855,6470,1362,562,9195,4519,1011,9384,2988,4631,7258,4714,5493,8617,5249,1522 };
//    int k = 3;
//    Solution().getAverages(nums, 7875);
//}