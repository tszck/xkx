//Room: wulaofeng.c 五老峯
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","五老峯");
      set("long",@LONG
只見五座奇峯突兀，驚險無比，行人多不敢放膽在此玩賞風景。
LONG);
      set("exits",([ /* sizeof() == 1 */
          "northdown": __DIR__"sanlaofeng",
          "southup"  : __DIR__"hutouyan",
      ]));
      set("objects",([ /* sizeof() == 1 */
          "/clone/medicine/vegetable/tenghuang" : random(2),
      ]));
      set("outdoors", "wudang");
      set("no_clean_up", 0);
	set("coor/x", -2030);
	set("coor/y", -970);
	set("coor/z", 130);
	setup();
      replace_program(ROOM);
}