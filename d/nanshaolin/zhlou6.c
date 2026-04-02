// Room: /d/nanshaolin/zhlou6.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "鐘樓六層");
	set("long", @LONG
沿窗洞吹進一陣陣凌厲的山風，寒意浸人。北望可見松林的盡頭，
頭頂上的樓板開了個大洞，掛下一口大鐘。從這裏只能看到巨鐘的下邊
緣，內裏黑洞洞的，什麼也看不見。
LONG );
	set("exits", ([
		"up"   : __DIR__"zhlou7",
		"down" : __DIR__"zhlou5",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1840);
	set("coor/y", -6280);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}

