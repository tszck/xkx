//      neidian.c 內殿

inherit ROOM;

void create()
{
        set("short","內殿");
        set("long",@LONG
這裏是雪山寺的內殿，也是掌門人見客的地方。雪山寺的掌門人、
大輪明王、吐蕃國師鳩摩智是西域一代高僧，也是西域不世出的武林宗
師。他駐錫本寺後，雪山寺方聲名遠播。
LONG );
        set("exits",([
                "east" : __DIR__"tiantai",
                "west" : __DIR__"midao",
                "south" : __DIR__"zoulang3",
                "north" : __DIR__"houdian",
        ]));
        set("objects",([
                CLASS_D("xueshan")+"/jiumozhi" :1
        ]));
	set("coor/x", -70000);
	set("coor/y", -19880);
	set("coor/z", 140);
	setup();
        replace_program(ROOM);
}
