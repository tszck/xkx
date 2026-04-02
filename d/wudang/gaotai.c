//Room: gaotai.c 南巖宮高臺
//Date: Sep 29 1997

#include <ansi.h>
inherit ROOM;

void create()
{
      set("short","南巖宮高臺");
      set("long",@LONG
這裏是就是南巖宮高臺。高臺孤懸崖側，四望臨淵，深不可測。山
風夾耳，松清滌面，頓覺心竅大開。
    武當真武劍陣就在這裏。真武劍陣由五名五行弟子按東西南北中的
木、金、火、水、土方位，八名八卦弟子按乾、坤、坎、離、巽、震、
艮、兌八方天、地、水、火、風、雷、山、澤排列。
LONG);
      set("objects", ([
           CLASS_D("wudang") +"/wuxing": 5,
           CLASS_D("wudang") +"/bagua": 8,
           CLASS_D("wudang") +"/yan": 1,
      ]));
      set("exits",([ /* sizeof() == 1 */
          "northdown" : __DIR__"nanyangong",
      ]));
      set("outdoors", "wudang");
//      set("no_clean_up", 0);
	set("coor/x", -2040);
	set("coor/y", -970);
	set("coor/z", 100);
	setup();
      replace_program(ROOM);
}
