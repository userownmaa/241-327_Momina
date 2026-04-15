from django.contrib import admin

# Register your models here.


from django.contrib import admin
from .models import Medicine

@admin.register(Medicine)
class MedicineAdmin(admin.ModelAdmin):
    list_display = ['name', 'manufacturer', 'price', 'quantity_in_stock', 
                   'expiration_date', 'requires_prescription']
    list_filter = ['requires_prescription', 'expiration_date']
    search_fields = ['name', 'manufacturer', 'description']
    readonly_fields = []
    
    fieldsets = (
        ('Основная информация', {
            'fields': ('name', 'manufacturer', 'price', 'description')
        }),
        ('Склад и срок годности', {
            'fields': ('quantity_in_stock', 'expiration_date', 'requires_prescription')
        }),
    )