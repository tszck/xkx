//Room: songlin1.c 松林
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","松林");
      set("long",@LONG
這是松林深處，暗無天日，朦朧中只感覺到左右前後到處都是樹影。
地上有一兩個死人骷髏，發着綠熒熒的磷光。你驚駭之間，一腳踩在鋼
針般的松針上！
LONG);
      set("objects", ([
           CLASS_D("wudang") +"/famu": 2,
      ]));
      set("outdoors", "wudang");
      set("exits",([ /* sizeof() == 1 */
          "north"  : __DIR__"slxl2",
          "south"  : __DIR__"songlin3",
      ]));
//      set("no_clean_up", 0);
	set("coor/x", -2020);
	set("coor/y", -810);
	set("coor/z", 0);
	setup();
      replace_program(ROOM);
}
