//Room: sanlaofeng.c 三老峯
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","三老峯");
      set("long",@LONG
只見三座奇峯突兀，驚險無比，行人多不敢放膽在此玩賞風景。
LONG);
      set("exits",([ /* sizeof() == 1 */
          "northdown": __DIR__"wuyaling",
          "southup"  : __DIR__"wulaofeng",
      ]));
      set("outdoors", "wudang");
      set("no_clean_up", 0);
	set("coor/x", -2030);
	set("coor/y", -960);
	set("coor/z", 120);
	setup();
      replace_program(ROOM);
}