#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "../src/recipe.h"
#include "../src/hash_table.h"
#include "../src/linked_list.h"

int total_tests = 0;
int passed_tests = 0;

void run_test(const char* name, int condition) {
    total_tests++;
    if (condition) {
        passed_tests++;
        printf("[✓] %s\n", name);
    }
    else {
        printf("[✗] %s\n", name);
    }
}

int main() {
    printf("=== UNIT TEST BASLADI ===\n\n");

    // Test 1: recipe_create()
    Recipe* r = recipe_create(1, "Pizza", "Lunch", 800, 45);
    run_test("recipe_create -> isim kontrolü", strcmp(r->name, "Pizza") == 0);
    run_test("recipe_create -> kategori kontrolü", strcmp(r->category, "Lunch") == 0);
    run_test("recipe_create -> kalori kontrolü", r->calories == 800);
    run_test("recipe_create -> sure kontrolü", r->preparation_time == 45);

    // Test 2: recipe_compare_by_calories()
    Recipe* r2 = recipe_create(2, "Salata", "Dinner", 300, 15);
    int cmp = recipe_compare_by_calories(r, r2);
    run_test("recipe_compare_by_calories -> pozitif değer", cmp > 0);

    // Test 3: Liste testleri
    List* lst = list_create();
    list_insert_tail(lst, r);
    list_insert_tail(lst, r2);
    run_test("list_size -> 2 eleman var", list_size(lst) == 2);
    run_test("list_find -> Pizza bulundu", list_find(lst, 1) == r);

    // Test 4: Hash table testleri
    HashTable* ht = hash_table_create(10);
    hash_table_insert(ht, r);
    hash_table_insert(ht, r2);
    run_test("hash_table_search -> Pizza bulundu", hash_table_search(ht, 1) == r);

    // Sonuç
    printf("\n---------------------------------\n");
    printf("Toplam test sayısı: %d\n", total_tests);
    printf("Başarılı test sayısı: %d\n", passed_tests);

    double oran = (passed_tests * 100.0) / total_tests;
    printf("Doğruluk oranı: %.2f%%\n", oran);
    printf("---------------------------------\n");

    if (oran >= 95.0)
        printf(" TESTLER BAŞARILI (%%%.2f)\n", oran);
    else
        printf(" TESTLER YETERSİZ (%%%.2f)\n", oran);

    return 0;
}
