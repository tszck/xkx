//Room: qsjie1.c 青石階
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","青石階");
      set("long",@LONG
快到峨嵋山了。這是一條通往峨嵋山的青石階，兩旁綠樹廕庇，空氣十分
清新。時常能見到些遊人香客。
LONG);
      set("objects", ([
               __DIR__+"npc/youngwoman": 1,
               __DIR__+"npc/puren": 1,
      ]));
      set("outdoors", "sanbuguan");
      set("exits",([ /* sizeof() == 1 */
          "west"       : "/d/chengdu/road1",
          "north"      : __DIR__"xiaolu2",
          "southwest"  : __DIR__"qsjie2",
      ]));
//      set("no_clean_up", 0);
	set("coor/x", -6000);
	set("coor/y", -1010);
	set("coor/z", 0);
	setup();
      replace_program(ROOM);
}
