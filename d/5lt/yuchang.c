// Room: /d/5lt/yuchang.c

inherit ROOM;
int do_jump(string arg);

void create()
{
	set("short", "海濱浴場");
	set("long", @LONG
這是一個非常乾淨的海濱浴場，每到夏季這裏就變成全村最熱鬧的地
方，在這兒可以深海潛水、出海釣魚、衝浪和游泳。海邊的碼頭(pier)
還可以看到一艘豪華遊艇。
LONG);
	set("outdoors", "5lt");
	set("exits", ([
		"east"  : __DIR__"haitan",
	]));
	set("objects",  ([
		__DIR__"npc/sunray": 1,
	]));
	set("no_fight", "1");
	set("coor/x", -205);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
}