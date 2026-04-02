// Room: /d/tiezhang/hclu3.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "荒草路");
	set("long", @LONG
你走在一條荒蕪的小路上，兩旁荒草齊膝，荊棘遍地，似乎罕有人
至。山石壁立，遮天蔽日，鳥獸全無，四周籠罩在一片陰暗之中，使這
裏看起來格外深隧幽靜。
LONG	);
	set("exits", ([ /* sizeof() == 2 */
		"southeast" : __DIR__"hclu2",
		"northup"   : __DIR__"hclu4",
	]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");
	set("coor/x", -2060);
	set("coor/y", -1880);
	set("coor/z", 60);
	setup();
}
int valid_leave(object me, string dir)
{
	if (me->query("family/family_name") == "鐵掌幫") return 1;
	if ((dir != "northup") && (dir != "southeast"));
	if (dir == "northup")
	{
		me->receive_damage("qi", 5);       
		write("你的雙腿被荊棘刺破，鮮血流了出來。\n");
	}
	if (dir == "southeast")
	{
		me->receive_damage("qi", 5);       
		write("你的雙腿被荊棘刺破，鮮血流了出來。\n");
	}
	return 1;
}
