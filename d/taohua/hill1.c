// Room: /d/taohua/hill1.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "山脊");
	set("long", @LONG
山勢至此一轉，折而向北就可抵達山頂。往遠處望，一片桃花鬱鬱
蔥蔥，另一邊則可遠眺大海，極目海天交接處，似乎有些帆影，但又似
乎是幻覺。
LONG
	);
	set("exits", ([ 
		"westdown" : __DIR__"hill",
		"northup" : __DIR__"hill2",
	]) );
	set("no_clean_up", 0);
	set("outdoors","taohua");

	set("coor/x", 8510);
	set("coor/y", -4690);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}