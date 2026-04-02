//Room: bgsxq.c 報國寺西牆
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","西牆");
      set("long",@LONG
這裏是峨眉山報國寺的西牆。寺院裏的鐘聲從牆那邊飄來，在空氣中回
響。一條山溪從西面山上的解脫橋下流經這裏，向山下淌去。
LONG);
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
          "east"      : __DIR__"bgs",
      ]));
      set("no_clean_up", 0);
	set("coor/x", -6030);
	set("coor/y", -1030);
	set("coor/z", 10);
	setup();
      replace_program(ROOM);
}