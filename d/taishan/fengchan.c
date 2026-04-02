// Room: /d/taishan/fengchan.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "封禪臺");
	set("long", @LONG
如今這裏是推選天下武林總盟主之處，各路英雄如能技壓羣雄，比
武奪魁，便能問鼎盟主寶座，成爲統領中原武林的領袖。高臺上擺放着
漢白玉寶座，盟主便在此坐堂議事。臺上高高立着一竿旗，上書：“替
天行道”四個大字。盟主左右各侍立着兩位白衣武士，兩邊都放着一長
排虎皮交椅，時常有武林前輩高手前來參見盟主。
LONG );
	set("exits", ([
		"down" : __DIR__"yuhuang",
		"east" : __DIR__"xiayi",
		"west" : __DIR__"zhengqi",
	]));
	set("objects",([
		"/clone/npc/meng-zhu" : 1,
		__DIR__"npc/wei-shi1" : 4,
	]));
	set("outdoors", "taishan");
	set("coor/x", 410);
	set("coor/y", 630);
	set("coor/z", 120);
	setup();
	replace_program(ROOM);
}
