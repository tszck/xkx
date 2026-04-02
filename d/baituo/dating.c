// Room: /d/baituo/dating.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short", "大廳");
	set("long", @LONG
這是『白駝山莊』的大廳，內部擺設極盡豪華，當中一張黑色檀木
條案，上面陳放着精美的花瓶和一些珍貴的瓷器，四壁掛滿名家的字畫。
LONG	);
	set("valid_startroom",1);
	set("exits", ([
		"north" : __DIR__"liangong",
		"southdown" : __DIR__"kongdi",
	]));
	set("objects",([
		CLASS_D("baituo")+"/ouyangfeng" : 1,
		__DIR__"npc/yahuan" : 2,
	]));
	set("coor/x", -50010);
	set("coor/y", 20030);
	set("coor/z", 30);
	setup();
	"/clone/board/baituo_b"->foo();
	replace_program(ROOM);
}
