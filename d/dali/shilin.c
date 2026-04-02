//Room: /d/dali/shilin.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","路南石林");
	set("long",@LONG
在綠樹叢中隨處可見峭石插天，石筍叢集，石柱挺立，奇異詭質，
各呈異姿。這裏石峯攢聚，如劍戟排空，莽莽蒼蒼，儼然一片林海，
蔚爲壯觀。更加叢山之中或飛瀑直瀉，成疊水噴雲，或山泉匯聚，成
明鏡長湖。
LONG);
	set("outdoors", "dalin");
	set("exits",([ /* sizeof() == 1 */
	    "northup"  : __DIR__"changhu",
	    "south"    : __DIR__"cangshan",
	]));
	set("no_clean_up", 0);
	set("coor/x", -38000);
	set("coor/y", -55000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}