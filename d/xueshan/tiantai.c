//      tiantai.c 天台

inherit ROOM;

void create()
{
        set("short","天台");
        set("long",@LONG
這裏是雪山寺的高處。北邊可見雄偉的大雪山，南邊可以俯瞰美麗
如鏡的聖湖。
LONG );
	set("outdoors", "xueshansi");
        set("exits",([
                "west" : __DIR__"neidian",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -69990);
	set("coor/y", -19880);
	set("coor/z", 140);
	setup();
        replace_program(ROOM);
}
