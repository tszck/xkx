// /clone/shop/fuzhou_shop.c
// Last modified by winder 2003.10.20

inherit SHOP;

void create()
{
	set("short", "聚春園");
	set("no_fight", 1);
	set("no_beg", 1);
	set("owner", "VOID_SHOP");
	set("exits", ([
                "down" : "/d/fuzhou/majiu",
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
聚春園是福州城內有名的店鋪，店堂正中掛着的一塊匾額，匾上大
書「三山聚春」四個大字，令人心胸大開。不過店裏的貨櫃上卻空無一
物，看樣子已經很久沒人來打理了。
LONG);
	else
		set("long", @LONG
聚春園是福州城內有名的店鋪，店堂正中掛着的一塊匾額，匾上大
書「三山聚春」四個大字，令人心胸大開。整個鋪面寬敞明亮，櫃上擺
滿了各式各樣、琳琅滿目的貨物。
LONG);
        return;
}

