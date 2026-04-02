// Room: /d/baituo/huayuan.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short", "大花園");
	set("long", @LONG
這是個美麗的大花園，園子裏面種着鮮豔的紅玫瑰。白衣少女常來
這裏嬉戲。沿着彎彎曲曲的花徑，可以通到山莊的許多地方。東邊是廚
房。西邊是白駝山少主『歐陽克』的內室，門虛掩着，不知主人在不在。
LONG	);
	set("exits",([
		"west"  : __DIR__"neishi",
		"north" : __DIR__"zhuyuan",
		"east"  : __DIR__"chufang",
		"south" : __DIR__"tuitang",
	]));
	set("outdoors", "baituo");
	set("objects",([
		__DIR__"npc/whitelady" : 2,
	]));
	set("coor/x", -50010);
	set("coor/y", 20060);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}




