/*
* Page Table Implementation
* Specifications : Multi Level Page table
*
*/

#define INDEX_LENGTH 10
#define SUB_INDEX_LENGTH 10
#define OFFSET 12

#define SUB_INDEX_SIZE (1 << OFFSET)
#define INDEX_SIZE (1 << (OFFSET + SUB_INDEX_LENGTH))

#define INDEX(addr) (addr % INDEX_SIZE) >> (OFFSET + SUB_INDEX_LENGTH)
#define SUB_INDEX(addr) (addr % SUB_INDEX_SIZE)  >> OFFSET
#define OFFSET(addr) addr %  PAGE_SIZE

#define PAGE_TABLE_SIZE (1 << INDEX_LENGTH)
#define SUB_PAGE_TABLE_SIZE (1 << SUB_INDEX_LENGTH)

struct dir_table_entry_t {
	uint32_t tag;
	struct page_table_t* sub_page_table;
};

struct page_table_entry {
	uint32_t tag;
	int valid_bit;
	int reference_bit;
	int dirty_bit;
	mem_page_t* page; 
};

struct dir_table_t {
	struct dir_table_entry* dir_hash_table[DIR_TABLE_SIZE];
};

struct page_table_t {
	uint32_t index; // same as correspoinding dir_table_entry.tag
	struct dir_table_t* dir_table_ptr;
	struct page_table_entry* page_hash_table[PAGE_TABLE_SIZE];
};

void dir_table_init() {
	//
}

void page_table_init(uint32_t tag, dir_table_init* _dir_table_ptr) {
	index = tag;
	dir_table_ptr = _dir_table_ptr;
	//
}

uint32_t vm_translate(dir_table_t* dt, uint32_t vtladdr) {
	
}
