//Room: huixianqiao.c 會仙橋
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","會仙橋");
      set("long",@LONG
這裏地勢稍平，一道山澗緩緩流過，一座窄窄的木橋橫在澗上，只
容一人經過。
LONG);
      set("exits",([ /* sizeof() == 1 */
          "north"    : __DIR__"chaotiangong",
          "south"    : __DIR__"toutiangate",
      ]));
      set("outdoors", "wudang");
      set("no_clean_up", 0);
	set("coor/x", -2030);
	set("coor/y", -1000);
	set("coor/z", 150);
	setup();
      replace_program(ROOM);
}
