//Room: wdroad.c 大道
//Date: Oct.2.1997 by That

inherit ROOM;

void create()
{
      set("short", "黃土大道");
      set("long", @LONG
你走在一條黃土大道上，不時地有人掛劍跨馬匆匆而過。
    東北通向武當。
LONG);
      set("outdoors", "sanbuguan");
      set("exits", ([
          "southwest" : __DIR__"xiaolu1",
          "northeast" : "/d/wudang/sanbuguan",
      ]));
      set("no_clean_up", 0);
	set("coor/x", -3400);
	set("coor/y", 900);
	set("coor/z", 0);
	setup();
      replace_program(ROOM);
}