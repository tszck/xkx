//Room: hcawest2.c 華藏庵西廊
//Date: Oct. 2 1997 by That

inherit ROOM;
void create()
{
      set("short","華藏庵西廊");
      set("long",@LONG
這裏是峨嵋華藏庵西廊。走廊往南禪房，北邊通往廣場。
LONG);
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
          "south" : __DIR__"hcachanfang",
          "north" : __DIR__"hcawest1", 
      ]));
      set("no_clean_up", 0);
	set("coor/x", -6210);
	set("coor/y", -1180);
	set("coor/z", 190);
	setup();
      replace_program(ROOM);
}