//Room: wuyaling.c 烏鴉嶺
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","烏鴉嶺");
      set("long",@LONG
這是一狹長的脊嶺，兩側懸削，一無所傍，但見白雲朵朵，冉冉而
過，山風拂拂，陣陣襲來。數百隻烏鴉正翱翔雲際，黑白分明，蔚成奇
觀。
LONG);
      set("objects", ([
                __DIR__"npc/wuya" : 5,
      ]));
      set("exits",([ /* sizeof() == 1 */
          "northdown": __DIR__"langmeiyuan",
          "southup"  : __DIR__"sanlaofeng",
      ]));
      set("outdoors", "wudang");
//      set("no_clean_up", 0);
	set("coor/x", -2030);
	set("coor/y", -950);
	set("coor/z", 110);
	setup();
      replace_program(ROOM);
}
