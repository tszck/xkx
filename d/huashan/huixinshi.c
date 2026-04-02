// huixinshi.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{
	set("short", "迴心石");
	set("long", @LONG
從青柯坪沿石階上山，山路到此而盡，前面山勢險惡，石崖間僅有
窄窄的石階猶如天梯聳立，兩邊鐵鏈斜懸，令人不寒而慄，不敢前行。
北壁下大石當路，此石因此叫做迴心石，再上去山道奇險，遊客至此，
就該回了。
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"westdown" : __DIR__"qingke",
		"eastup"   : __DIR__"qianchi",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huashan" );

	set("coor/x", -900);
	set("coor/y", 240);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
