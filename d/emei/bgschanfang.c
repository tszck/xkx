//Room: bgschanfang.c 禪房
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","禪房");
      set("long",@LONG
這兒是報國寺內的一間禪房，佈局簡單，供寺內和尚誦經修行之用。
LONG);
      set("exits",([ /* sizeof() == 1 */
          "east"    : __DIR__"dxdian",
      ]));
      set("sleep_room", 1);
      set("no_clean_up", 0);
      set("no_fight", 1);
	set("coor/x", -6030);
	set("coor/y", -1020);
	set("coor/z", 10);
	setup();
      replace_program(ROOM);
}