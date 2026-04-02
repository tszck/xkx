inherit ROOM;

void create()
{
        set("short", "大門");
        set("long",@LONG
天龍寺在大理城外點蒼山中嶽峯之北，正式寺名叫作崇聖寺，但大理
百姓叫慣了，都稱之為“天龍寺”。天龍寺揹負蒼山，面臨洱水，極佔形
勝。寺有三塔，建於唐初，大者高二百餘尺，十六級，塔頂有鐵鑄記雲：
“大唐貞觀尉遲敬德造。”相傳天龍寺有五寶，三塔為五寶之首。
    你來到了天龍寺大門前，只見氣勢恢弘的兩個大門柱上刻有一付對聯
( duilian ) ，紅漆覆字，頗有點撥眾生之意。抬頭上望，門楣上一塊黑
木大匾，上題“崇聖寺”三個大字，筆意蒼松。
LONG );
        set("outdoors", "tianlongsi");
        set("exits", ([
                "south" : __DIR__"talin",
//                "north" : __DIR__"dadao4",
                "north" : "/d/dali/hongsheng",
        ]));
	set("item_desc",([
		"duilian" : "\n    心性無染本自圓成　但離妄緣即如如佛\n\n",
	]));	
        set("objects",([
                "/d/wudang/npc/guest" : 1,
        ]));
//        set("no_clean_up", 0);
	set("coor/x", -37000);
	set("coor/y", -57000);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}