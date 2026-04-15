from django.contrib import admin

# Register your models here.


from django.contrib import admin
from .models import Medicine

@admin.register(Medicine)
class MedicineAdmin(admin.ModelAdmin):
    list_display = ['name', 'manufacturer', 'price', 'quantity_in_stock', 'expiration_date', 'is_available']
    list_filter = ['category', 'requires_prescription', 'expiration_date']
    search_fields = ['name', 'manufacturer']
    readonly_fields = ['created_at', 'updated_at']
    
    fieldsets = (
        ('Основная информация', {
            'fields': ('name', 'manufacturer', 'category', 'price')
        }),
        ('Складская информация', {
            'fields': ('quantity_in_stock', 'expiration_date', 'requires_prescription')
        }),
        ('Системная информация', {
            'fields': ('created_at', 'updated_at'),
            'classes': ('collapse',)
        }),
    )