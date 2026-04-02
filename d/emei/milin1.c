//Room: milin1.c 密林
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","密林");
      set("long",@LONG
這是黑森森的一片密林，楠木參天，濃陰蔽日。這裏東下二里是報國寺，
西邊林間隱藏着一座廟宇。
LONG);
      set("exits",([ /* sizeof() == 1 */
          "northeast"  : __DIR__"bgs",
          "west"       : __DIR__"fhs",
      ]));
      set("outdoors", "emei");
      set("no_clean_up", 0);
	set("coor/x", -6030);
	set("coor/y", -1040);
	set("coor/z", 10);
	setup();
      replace_program(ROOM);
}