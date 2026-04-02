//Room: hcawest1.c 華藏庵西廊
//Date: Oct. 2 1997 by That

inherit ROOM;
void create()
{
      set("short","華藏庵西廊");
      set("long",@LONG
這裏是峨嵋華藏庵西廊。走廊往南通往禪房，東邊通往廣場。
LONG);
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
          "south" : __DIR__"hcawest2",
          "east"  : __DIR__"hcaguangchang", 
      ]));
      set("no_clean_up", 0);
	set("coor/x", -6210);
	set("coor/y", -1170);
	set("coor/z", 190);
	setup();
      replace_program(ROOM);
}