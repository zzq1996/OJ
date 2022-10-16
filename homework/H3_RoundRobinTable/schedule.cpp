//
// Created by zhang on 10/13/22.
//

#include "schedule.h"


void schedule::CopyData(int **map, int sr, int sl, int dr, int dl, int k) {

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            map[dr + i][dl + j] = map[sr + i][sl + j];
        }
    }

}


void schedule::Table(int **map, int r, int l, int k) {

    if (1 == k) return;
    //填充左上角
    Table(map, r, l, k / 2);
    //填充右上角
    Table(map, r, l + (k / 2), k / 2);
    //从左上角拷贝到右下角
    CopyData(map, r, l, r + k / 2, l + k / 2, k / 2);
    //从右上角拷贝到左下角
    CopyData(map, r, l + k / 2, r + k / 2, l, k / 2);

}
