// yunuci.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{
	set("short", "玉女祠");
	set("long", @LONG
玉女祠裏供奉的到底是哪位玉女，有許多不同的説法，現在所能看
到的只一尊呆板的石像。祠中大石上有一處深陷，凹處積水清碧，這是
玉女的洗臉盆，碧水終年不幹。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"yunu",
	]));
	set("resource/water", 1);
	set("no_clean_up", 0);

	set("coor/x", -870);
	set("coor/y", 190);
	set("coor/z", 120);
	setup();
	replace_program(ROOM);
}
 
