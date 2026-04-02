//TOHTQ4.C

inherit ROOM;

void create()
{
	set("short", "山洞");
	set("long", @LONG
山洞中似乎深不可測，洞壁上點着幾盞松明，照得洞內一派光亮。
洞內雖然感到十分潮溼，可洞壁乾燥堅實，大異平常。
LONG );
	set("exits", ([
		"north" :__DIR__"tohtq5",
		"out"   :__DIR__"tohtq3",
	]));
	set("no_clean_up", 0);
	set("coor/x", -52040);
	set("coor/y", 900);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}