inherit ROOM;

void create()
{
        set("short", "清都瑤臺");
        set("long",@LONG
這是出入前後寺的必經之路。往南望去，可見後寺中亭臺樓閣規模宏
大，構築精麗，宅地連雲，其氣勢之盛更勝於五臺，普陀等諸處佛門勝地
的名山大寺。
LONG );
	set("outdoors","tianlongsi");
        set("exits", ([
		"south": __DIR__"wuwujing", 
		"north": __DIR__"huangtianmen",   			
        ]));
        set("no_clean_up", 0);
	set("coor/x", -37000);
	set("coor/y", -57050);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}