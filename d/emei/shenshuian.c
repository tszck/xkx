//Room: shenshuian.c 神水庵
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","神水庵");
      set("long",@LONG
神水庵位於寶掌峯下，庵前有大峨石和玉液泉，泉出石下，清澈無比，終
年不涸。一株大海棠樹，已是數百蒼齡，抱可數圍，高達十餘丈。旁邊有福壽
庵；由此西上中峯寺，東下純陽殿。
LONG);
      set("exits",([ /* sizeof() == 1 */
          "eastdown"  : __DIR__"chunyangdian",
          "westup"    : __DIR__"zhongfengsi",
          "south"     : __DIR__"fushouan",
      ]));
      set("outdoors", "emei");
      set("no_clean_up", 0);
	set("coor/x", -6100);
	set("coor/y", -1040);
	set("coor/z", 70);
	setup();
      replace_program(ROOM);
}