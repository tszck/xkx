//Room: shijie1.c 石階
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","石階");
      set("long",@LONG
你走在一條堅實的石階上，不時地有進香客從你的身邊走過。一邊
是峭壁，一邊是懸崖，抬頭隱約可見籠罩在雲霧中的天柱峯，聽着流水
淙淙，令人心曠神怡。
LONG);
      set("objects", ([
          __DIR__+"npc/guest": 2,
      ]));
      set("outdoors", "wudang");
      set("exits",([ /* sizeof() == 1 */
          "northdown"  : __DIR__"xuanyuegate",
          "southup"    : __DIR__"yuzhengong",
      ]));
//      set("no_clean_up", 0);
	set("coor/x", -2050);
	set("coor/y", -810);
	set("coor/z", 30);
	setup();
      replace_program(ROOM);
}
