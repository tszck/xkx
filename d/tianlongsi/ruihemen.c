inherit ROOM;

void create()
{
        set("short", "瑞鶴門");
        set("long",@LONG
這是通往天龍寺後寺的門戶。你低頭看看地上，只見銅門檻早已被踩
踏得鋥亮，足見此寺香火之盛了。抬頭向南可以望見點蒼山聳立雲天。
LONG );
	set("outdoors","tianlongsi");
        set("exits", ([
		"south": __DIR__"wuchangge",
		"north": __DIR__"wuwoge",
	]));
        set("no_clean_up", 0);
	set("coor/x", -36990);
	set("coor/y", -57030);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}