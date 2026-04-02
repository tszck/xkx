// Room: /d/5lt/yanwuqiao.c

inherit ROOM;

void create()
{
	set("short", "演武橋");
	set("long", @LONG
這是一座別緻的小橋，橋欄上雕刻了許多花草動物，栩栩如生。橋
邊新裝了好幾盞聚光燈，晚上燈亮起來的時候，簡直是座水晶做的橋。
LONG);
	set("exits", ([
		"south"   : __DIR__"sroad2",
		"north"   : __DIR__"sroad1",
	]));
	set("outdoors", "5lt");
	set("no_clean_up", 0);

	set("coor/x", -150);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
