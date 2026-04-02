//Room: majiu.c 馬廄
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","馬廄");
      set("long",@LONG
這是關外的馬廄，關外苦寒之地，頗乏新鮮草料。但東北大漢慣能
喫苦，馬伕們會把馬牽到馬廄好生照看，將它們餵飽飲足，再洗刷得幹
乾淨淨，一直伺候到客人上路。馬廄雪披下的木柱上歪歪地釘着一塊破
木牌(paizi)。
LONG);
      set("outdoors", "guanwai");
      set("no_fight", "1");
      set("no_beg", "1");
      set("objects", ([
	    "/d/city/npc/zaohongma": 1,
	    "/d/city/npc/huangbiaoma": 1,
	    "/d/city/npc/ziliuma": 1,
		"/clone/misc/mafu": 1,
      ]));
      set("item_desc", ([
          "paizi": @TEXT
客人們只要給馬伕一兩白銀的租金就可以僱到一匹馬了。

前往      北京城:  ridebj


TEXT]));
      set("exits",([ /* sizeof() == 1 */
          "east"      : __DIR__"jishi",
      ]));
      set("no_clean_up", 0);
	set("coor/x", 6030);
	set("coor/y", 5210);
	set("coor/z", 0);
	setup();
      replace_program(ROOM);
}
