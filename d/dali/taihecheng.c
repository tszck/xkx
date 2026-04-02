//Room: /d/dali/taihecheng.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","太和城");
	set("long",@LONG
此城是烏夷族的治府，全城巷陌都以石壘成，高丈餘，連綿數裏
不斷。太和不算大城，但人口爲數並不少，地理上和軍事上是大理城
的北門戶，歷代大理王朝都在此加固城池，派駐精兵。附近有一些烏
夷部族聚居。此南是一片平原，下十五里便達大理城。
LONG);
	set("outdoors", "dalin");
	set("objects",([
	    __DIR__"npc/bing": 2,
	    __DIR__"npc/jiang": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "north"  : __DIR__"dehuabei",
	    "south"  : __DIR__"dalinorth",
	]));
	set("coor/x", -40000);
	set("coor/y", -50000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}