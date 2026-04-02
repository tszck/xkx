// Room: /d/chengdu/xiaoting.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "小亭");
	set("long",@LONG
這裏是個修築精緻的小亭，遊人們到了這裏，總喜歡進來乘涼，這
裏涼風習習，且可撫覽府河美景，不亦快哉！
LONG
	);
	set("outdoors", "chengdu");
	set("exits", ([
		"southwest" : __DIR__"funanhe2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8030);
	set("coor/y", -3000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);       
}


