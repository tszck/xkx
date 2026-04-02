//Room: zixiaogonggate.c 紫霄宮大門
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","紫霄宮大門");
      set("long",@LONG
你已走到了展旗峯下，前面就是武當山最爲宏大的宮宇紫霄宮了。
殿宇依山而築，高低錯落有致。周圍古木森森，翠竹成林，景色清幽
。這裏是武當師徒的主要活動場所。
LONG);
      set("exits",([ /* sizeof() == 1 */
          "northdown"  : __DIR__"shijie2",
          "southup"    : __DIR__"guangchang",
      ]));
      set("outdoors", "wudang");
      set("no_clean_up", 0);
	set("coor/x", -2050);
	set("coor/y", -900);
	set("coor/z", 80);
	setup();
      replace_program(ROOM);
}