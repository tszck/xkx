//Room: /d/henshan/huiyang.c
// Modified By Java Feb.14.1998

inherit ROOM;

void create()
{
	set("short", "回雁樓");
	set("long", @LONG
這裏是衡陽回雁樓，是本地最大的酒樓。往日這時已經十分忙碌的
酒樓今天卻有點異樣。一個年近四十的白衣漢子，正端坐自飲，桌面橫
放着一把快刀，旁邊卻坐着一個小尼姑，滿臉憂急愁苦之色，容貌卻十
分秀麗。
LONG );
	set("exits", ([
		"down" : __DIR__"shop",
	]));
	set("objects", ([
		__DIR__"npc/tian" : 1,
		CLASS_D("hengshan")+"/lin" : 1,
	]));
//	set("no_clean_up", 0);

	set("coor/x", -400);
	set("coor/y", -1210);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
