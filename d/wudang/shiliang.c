//Room: shiliang.c 石樑
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","石樑");
      set("long",@LONG
你走入山塢中，有一道石樑跨溪而建，這裏是九渡澗的下流，各嶺
之水均在此交匯，景色極佳。附近設有許多小喫店，遊人至此，大多小
住歇歇腳力。再往上就是陡峭的十八盤了。
LONG);
      set("exits",([ /* sizeof() == 1 */
          "northup"    : __DIR__"taizipo",
          "southup"    : __DIR__"shibapan",
          "east"       : __DIR__"shop",
      ]));
      set("objects", ([
          "/clone/medicine/vegetable/shengdi" : random(2),
      ]));
      set("outdoors", "wudang");
	set("coor/x", -2050);
	set("coor/y", -870);
	set("coor/z", 50);
	setup();
      replace_program(ROOM);
}
