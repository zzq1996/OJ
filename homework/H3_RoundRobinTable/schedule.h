//
// Created by zhang on 10/13/22.
//

#ifndef OJ_SCHEDULE_H
#define OJ_SCHEDULE_H

/*
 * @Description 生成循环赛日程表
 */

class schedule {

public:
    static void Table(int **map, int r, int l, int k);
    static void CopyData(int **map, int sr, int sl, int dr, int dl, int k);

};


#endif //OJ_SCHEDULE_H
