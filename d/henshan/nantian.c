// Room: /d/henshan/nantian.c
// Date: Nov.1997 by Venus

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "南天門");
        set("long", @LONG
到了南天門，才能望到衡山第一的祝融峯。南天門是花崗巖的石碑
坊，中門鐫有 "南天門" 三字橫額，左右二門的門楣上，分別刻有 "行
雲" ， "施雨" 。楹聯(lian)破陋，顯見歲月已久。
LONG);
        set("exits", ([
            "northeast" : __DIR__"shiziyan",
            "southup"   : __DIR__"denggaotai",
            "eastup"    : __DIR__"liuyunping",
            "southwest" : __DIR__"shanlu13",
            "northwest" : __DIR__"shanlu14",
        ]));
        set("item_desc", ([
            "lian" :
"\n
        門              路
        可              承
        通              絕
        天              頂

        仰              俯
        觀              瞰
        碧              翠
        落              微
        星              巒
        辰              嶼
        近              低\n\n",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
	set("coor/x", -320);
	set("coor/y", -1020);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}
