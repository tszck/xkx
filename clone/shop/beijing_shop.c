// beijing_shop.c
// Last modified by winder 2003.10.20

inherit SHOP;

void create()
{
	set("short", "瑞蚨祥");
	set("no_fight", 1);
	set("no_beg", 1);
	set("owner", "VOID_SHOP");
	set("exits", ([
                "down" : "/d/beijing/majiu",
        ]));
	set("no_steal", 1);
	set("objects", ([
                __DIR__"waiter" : 1,
        ]));
	set("no_clean_up", 0);
	set("shop_type", 0);

	setup();
}

void init()
{
	if (query("shop_type") == 0)
		set("long", @LONG
這裏便是北京城裏最有名的瑞蚨祥，鋪里人來人往，川流不息，顯
出天子之都繁華大方的氣派。不過店裏的貨櫃上卻空無一物，看樣子已
經很久沒人來打理了。
LONG);
	else
		set("long", @LONG
這裏便是北京城裏最有名的瑞蚨祥，鋪里人來人往，川流不息，顯
出天子之都繁華大方的氣派。鋪面寬敞明亮，櫃上擺滿了各式各樣、琳
琅滿目的貨物。
LONG);
        return;
}
