// Room: /d/taohuacun/taohua3.c

inherit ROOM;

string look_shibei();
void create()
{
	set("short", "桃花谷");
	set("long", @LONG
順溪流而上，兩邊山勢漸高，流水漸急，桃林也愈見密集，層
層桃花擁攢成一片晚霞，留心處，時時可見懸泉飛瀑，倒掛崖間。
桃花溪水跳蕩起伏，青鱗赤鯉隱隱相戲。這裏就是桃花谷了。谷口
一個尺許高的小篆石碑(shibei)斜側路旁。
LONG );
	set("outdoors", "taohuacun");
	set("no_clean_up", 0);
	set("item_desc", ([
		"shibei" : (: look_shibei :),
	]));
	set("exits", ([
		"eastdown" : __DIR__"taohua2",
		"northup"  : __DIR__"taohua4",
	]));
        set("objects", ([
                "/clone/medicine/vegetable/taohuaban" : random(2),
        ]));
	set("coor/x", -110);
	set("coor/y", 10);
	set("coor/z", 10);
	setup();
}

string look_shibei()
{
        return
        "******************************\n"
        "****                      ****\n"
        "****        桃花村        ****\n"
        "****                      ****\n"
        "******************************\n";
}
