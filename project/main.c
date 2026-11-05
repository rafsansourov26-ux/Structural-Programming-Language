#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ORGS 50
#define MAX_EMPLOYEES 100
#define STR_LEN 100
#define DATA_FILE "organisations.txt"

// Employee structure
struct Employee {
    int id;
    char name[STR_LEN];
    char designation[STR_LEN];
    double salary;
    char email[STR_LEN];
};

// Organisation structure
struct Organisation {
    int id;
    char name[STR_LEN];
    char location[STR_LEN];
    char category[STR_LEN]; // e.g. IT, Education, Finance, Healthcare
    int established_year;
    char contact_email[STR_LEN];
    int emp_count;
    struct Employee employees[MAX_EMPLOYEES];
};

// Global array to store organisations
struct Organisation orgs[MAX_ORGS];
int org_count = 0;

// Helper to remove newline from fgets input
void removeNewline(char *str) {
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

// Clear leftover input buffer from scanf
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Convert string to lowercase for case-insensitive search
void toLowerCase(char *dest, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = tolower((unsigned char)src[i]);
        i++;
    }
    dest[i] = '\0';
}

// Check if string contains search keyword (case-insensitive)
int containsText(const char *text, const char *pattern) {
    char lower_text[STR_LEN];
    char lower_pattern[STR_LEN];
    toLowerCase(lower_text, text);
    toLowerCase(lower_pattern, pattern);
    return strstr(lower_text, lower_pattern) != NULL;
}

// Save all organisations and employee data to file
void saveData() {
    FILE *fp = fopen(DATA_FILE, "w");
    if (fp == NULL) {
        printf("Error: Could not open file to save data.\n");
        return;
    }

    fprintf(fp, "%d\n", org_count);
    for (int i = 0; i < org_count; i++) {
        fprintf(fp, "%d\n", orgs[i].id);
        fprintf(fp, "%s\n", orgs[i].name);
        fprintf(fp, "%s\n", orgs[i].location);
        fprintf(fp, "%s\n", orgs[i].category);
        fprintf(fp, "%d\n", orgs[i].established_year);
        fprintf(fp, "%s\n", orgs[i].contact_email);
        fprintf(fp, "%d\n", orgs[i].emp_count);

        for (int j = 0; j < orgs[i].emp_count; j++) {
            fprintf(fp, "%d\n", orgs[i].employees[j].id);
            fprintf(fp, "%s\n", orgs[i].employees[j].name);
            fprintf(fp, "%s\n", orgs[i].employees[j].designation);
            fprintf(fp, "%.2f\n", orgs[i].employees[j].salary);
            fprintf(fp, "%s\n", orgs[i].employees[j].email);
        }
    }

    fclose(fp);
    printf("Data saved successfully to %s\n", DATA_FILE);
}

// Load data from file on program start
void loadData() {
    FILE *fp = fopen(DATA_FILE, "r");
    if (fp == NULL) {
        // file doesn't exist yet, start clean
        return;
    }

    if (fscanf(fp, "%d\n", &org_count) != 1) {
        fclose(fp);
        return;
    }

    for (int i = 0; i < org_count; i++) {
        fscanf(fp, "%d\n", &orgs[i].id);
        fgets(orgs[i].name, STR_LEN, fp);
        removeNewline(orgs[i].name);
        fgets(orgs[i].location, STR_LEN, fp);
        removeNewline(orgs[i].location);
        fgets(orgs[i].category, STR_LEN, fp);
        removeNewline(orgs[i].category);
        fscanf(fp, "%d\n", &orgs[i].established_year);
        fgets(orgs[i].contact_email, STR_LEN, fp);
        removeNewline(orgs[i].contact_email);
        fscanf(fp, "%d\n", &orgs[i].emp_count);

        for (int j = 0; j < orgs[i].emp_count; j++) {
            fscanf(fp, "%d\n", &orgs[i].employees[j].id);
            fgets(orgs[i].employees[j].name, STR_LEN, fp);
            removeNewline(orgs[i].employees[j].name);
            fgets(orgs[i].employees[j].designation, STR_LEN, fp);
            removeNewline(orgs[i].employees[j].designation);
            fscanf(fp, "%lf\n", &orgs[i].employees[j].salary);
            fgets(orgs[i].employees[j].email, STR_LEN, fp);
            removeNewline(orgs[i].employees[j].email);
        }
    }

    fclose(fp);
    printf("Loaded %d organisation(s) from %s\n", org_count, DATA_FILE);
}

// Find index of organisation by ID
int findOrgById(int id) {
    for (int i = 0; i < org_count; i++) {
        if (orgs[i].id == id) {
            return i;
        }
    }
    return -1;
}

// Add a new organisation
void addOrganisation() {
    if (org_count >= MAX_ORGS) {
        printf("Limit reached! Cannot add more organisations.\n");
        return;
    }

    struct Organisation new_org;

    printf("\n--- Add New Organisation ---\n");
    printf("Enter Organisation ID (number): ");
    if (scanf("%d", &new_org.id) != 1) {
        printf("Invalid input.\n");
        clearBuffer();
        return;
    }
    clearBuffer();

    if (findOrgById(new_org.id) != -1) {
        printf("Error: Organisation with ID %d already exists!\n", new_org.id);
        return;
    }

    printf("Enter Organisation Name: ");
    fgets(new_org.name, STR_LEN, stdin);
    removeNewline(new_org.name);

    printf("Enter Location (City/Country): ");
    fgets(new_org.location, STR_LEN, stdin);
    removeNewline(new_org.location);

    printf("Enter Category (e.g. IT, Education, Healthcare, NGO): ");
    fgets(new_org.category, STR_LEN, stdin);
    removeNewline(new_org.category);

    printf("Enter Established Year: ");
    if (scanf("%d", &new_org.established_year) != 1) {
        printf("Invalid year.\n");
        clearBuffer();
        return;
    }
    clearBuffer();

    printf("Enter Official Email: ");
    fgets(new_org.contact_email, STR_LEN, stdin);
    removeNewline(new_org.contact_email);

    new_org.emp_count = 0;

    // Ask if user wants to add employees now
    printf("Do you want to add employees right now? (1 for Yes / 0 for No): ");
    int choice;
    if (scanf("%d", &choice) == 1 && choice == 1) {
        clearBuffer();
        printf("How many employees to add? ");
        int n;
        if (scanf("%d", &n) == 1 && n > 0) {
            clearBuffer();
            for (int i = 0; i < n && new_org.emp_count < MAX_EMPLOYEES; i++) {
                struct Employee emp;
                printf("\nEmployee #%d:\n", i + 1);
                printf("  Enter Employee ID: ");
                scanf("%d", &emp.id);
                clearBuffer();

                printf("  Enter Name: ");
                fgets(emp.name, STR_LEN, stdin);
                removeNewline(emp.name);

                printf("  Enter Designation: ");
                fgets(emp.designation, STR_LEN, stdin);
                removeNewline(emp.designation);

                printf("  Enter Monthly Salary: ");
                scanf("%lf", &emp.salary);
                clearBuffer();

                printf("  Enter Email: ");
                fgets(emp.email, STR_LEN, stdin);
                removeNewline(emp.email);

                new_org.employees[new_org.emp_count++] = emp;
            }
        }
    } else {
        clearBuffer();
    }

    orgs[org_count++] = new_org;
    printf("\nOrganisation '%s' added successfully!\n", new_org.name);
}

// Display summary list of all organisations
void displayAllOrganisations() {
    if (org_count == 0) {
        printf("\nNo organisations found in the system.\n");
        return;
    }

    printf("\n================================== ALL ORGANISATIONS ==================================\n");
    printf("%-5s | %-25s | %-18s | %-15s | %-6s | %-10s\n", "ID", "Name", "Location", "Category", "Est.", "Employees");
    printf("---------------------------------------------------------------------------------------\n");

    for (int i = 0; i < org_count; i++) {
        printf("%-5d | %-25s | %-18s | %-15s | %-6d | %-10d\n",
               orgs[i].id,
               orgs[i].name,
               orgs[i].location,
               orgs[i].category,
               orgs[i].established_year,
               orgs[i].emp_count);
    }
    printf("=======================================================================================\n");
}

// View full profile of an organisation including its employees and stats
void viewOrganisationDetails() {
    if (org_count == 0) {
        printf("\nNo organisations available.\n");
        return;
    }

    int id;
    printf("\nEnter Organisation ID to view details: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid input.\n");
        clearBuffer();
        return;
    }
    clearBuffer();

    int idx = findOrgById(id);
    if (idx == -1) {
        printf("Organisation with ID %d was not found.\n", id);
        return;
    }

    struct Organisation *o = &orgs[idx];
    printf("\n------------------------------------------------------------\n");
    printf(" Organisation Profile: %s\n", o->name);
    printf("------------------------------------------------------------\n");
    printf(" ID               : %d\n", o->id);
    printf(" Location         : %s\n", o->location);
    printf(" Category         : %s\n", o->category);
    printf(" Established Year : %d\n", o->established_year);
    printf(" Contact Email    : %s\n", o->contact_email);
    printf(" Total Employees  : %d\n", o->emp_count);

    if (o->emp_count > 0) {
        double total_salary = 0.0;
        double max_salary = o->employees[0].salary;
        int max_idx = 0;

        printf("\n Employee List:\n");
        printf(" %-5s | %-20s | %-18s | %-10s | %-20s\n", "ID", "Name", "Designation", "Salary", "Email");
        printf(" ---------------------------------------------------------------------------------\n");
        for (int i = 0; i < o->emp_count; i++) {
            printf(" %-5d | %-20s | %-18s | %-10.2f | %-20s\n",
                   o->employees[i].id,
                   o->employees[i].name,
                   o->employees[i].designation,
                   o->employees[i].salary,
                   o->employees[i].email);
            total_salary += o->employees[i].salary;
            if (o->employees[i].salary > max_salary) {
                max_salary = o->employees[i].salary;
                max_idx = i;
            }
        }
        printf(" ---------------------------------------------------------------------------------\n");
        printf(" Total Payroll Expense : $%.2f / month\n", total_salary);
        printf(" Average Salary        : $%.2f\n", total_salary / o->emp_count);
        printf(" Highest Paid Employee : %s ($%.2f - %s)\n",
               o->employees[max_idx].name,
               o->employees[max_idx].salary,
               o->employees[max_idx].designation);
    } else {
        printf("\n (No employees added to this organisation yet)\n");
    }
    printf("------------------------------------------------------------\n");
}

// Add an employee to an existing organisation
void addEmployeeToOrganisation() {
    if (org_count == 0) {
        printf("\nNo organisations available.\n");
        return;
    }

    int id;
    printf("\nEnter Organisation ID to add an employee: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid input.\n");
        clearBuffer();
        return;
    }
    clearBuffer();

    int idx = findOrgById(id);
    if (idx == -1) {
        printf("Organisation with ID %d not found.\n", id);
        return;
    }

    if (orgs[idx].emp_count >= MAX_EMPLOYEES) {
        printf("Cannot add more employees. Maximum limit reached for this organisation.\n");
        return;
    }

    struct Employee emp;
    printf("Enter Employee ID: ");
    if (scanf("%d", &emp.id) != 1) {
        printf("Invalid input.\n");
        clearBuffer();
        return;
    }
    clearBuffer();

    // Check duplicate employee ID in this organisation
    for (int i = 0; i < orgs[idx].emp_count; i++) {
        if (orgs[idx].employees[i].id == emp.id) {
            printf("Error: An employee with ID %d already exists in %s!\n", emp.id, orgs[idx].name);
            return;
        }
    }

    printf("Enter Employee Name: ");
    fgets(emp.name, STR_LEN, stdin);
    removeNewline(emp.name);

    printf("Enter Designation: ");
    fgets(emp.designation, STR_LEN, stdin);
    removeNewline(emp.designation);

    printf("Enter Salary: ");
    if (scanf("%lf", &emp.salary) != 1) {
        printf("Invalid salary.\n");
        clearBuffer();
        return;
    }
    clearBuffer();

    printf("Enter Employee Email: ");
    fgets(emp.email, STR_LEN, stdin);
    removeNewline(emp.email);

    orgs[idx].employees[orgs[idx].emp_count++] = emp;
    printf("Employee '%s' added to %s successfully!\n", emp.name, orgs[idx].name);
}

// Search organisations by name, location, or category
void searchOrganisations() {
    if (org_count == 0) {
        printf("\nNo organisations available to search.\n");
        return;
    }

    printf("\nSearch By:\n");
    printf("1. Name\n");
    printf("2. Location\n");
    printf("3. Category\n");
    printf("Enter choice: ");

    int opt;
    if (scanf("%d", &opt) != 1) {
        printf("Invalid option.\n");
        clearBuffer();
        return;
    }
    clearBuffer();

    char query[STR_LEN];
    printf("Enter search keyword: ");
    fgets(query, STR_LEN, stdin);
    removeNewline(query);

    int found = 0;
    printf("\n--- Search Results ---\n");
    for (int i = 0; i < org_count; i++) {
        int match = 0;
        if (opt == 1 && containsText(orgs[i].name, query)) {
            match = 1;
        } else if (opt == 2 && containsText(orgs[i].location, query)) {
            match = 1;
        } else if (opt == 3 && containsText(orgs[i].category, query)) {
            match = 1;
        }

        if (match) {
            printf("[%d] %s | %s | %s | %d employees\n",
                   orgs[i].id, orgs[i].name, orgs[i].location, orgs[i].category, orgs[i].emp_count);
            found++;
        }
    }

    if (!found) {
        printf("No matching organisations found for '%s'.\n", query);
    } else {
        printf("Found %d matching organisation(s).\n", found);
    }
}

// Search employees across all organisations
void searchEmployees() {
    if (org_count == 0) {
        printf("\nNo organisations available to search.\n");
        return;
    }

    char query[STR_LEN];
    printf("\nEnter employee name or designation to search: ");
    fgets(query, STR_LEN, stdin);
    removeNewline(query);

    int found = 0;
    printf("\n--- Employee Search Results ---\n");
    for (int i = 0; i < org_count; i++) {
        for (int j = 0; j < orgs[i].emp_count; j++) {
            if (containsText(orgs[i].employees[j].name, query) ||
                containsText(orgs[i].employees[j].designation, query)) {
                printf("ID: %-4d | Name: %-20s | Role: %-15s | Organisation: %s (%s)\n",
                       orgs[i].employees[j].id,
                       orgs[i].employees[j].name,
                       orgs[i].employees[j].designation,
                       orgs[i].name,
                       orgs[i].location);
                found++;
            }
        }
    }

    if (!found) {
        printf("No employees found matching '%s'.\n", query);
    } else {
        printf("Total matches: %d\n", found);
    }
}

// Overall system summary and statistics
void showOverallStats() {
    if (org_count == 0) {
        printf("\nNo data recorded yet.\n");
        return;
    }

    int total_employees = 0;
    double grand_salary = 0.0;
    int max_emp_org_idx = 0;

    for (int i = 0; i < org_count; i++) {
        total_employees += orgs[i].emp_count;
        if (orgs[i].emp_count > orgs[max_emp_org_idx].emp_count) {
            max_emp_org_idx = i;
        }
        for (int j = 0; j < orgs[i].emp_count; j++) {
            grand_salary += orgs[i].employees[j].salary;
        }
    }

    printf("\n================ SYSTEM OVERVIEW ================\n");
    printf(" Total Organisations Registered : %d\n", org_count);
    printf(" Total Employees across all Orgs: %d\n", total_employees);
    printf(" Total Monthly Payroll Expense  : $%.2f\n", grand_salary);
    if (total_employees > 0) {
        printf(" Overall Average Salary         : $%.2f\n", grand_salary / total_employees);
    }
    printf(" Largest Organisation           : %s (%d employees)\n",
           orgs[max_emp_org_idx].name, orgs[max_emp_org_idx].emp_count);
    printf("=================================================\n");
}

// Delete an organisation
void deleteOrganisation() {
    if (org_count == 0) {
        printf("\nNo organisations available to delete.\n");
        return;
    }

    int id;
    printf("\nEnter Organisation ID to delete: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid input.\n");
        clearBuffer();
        return;
    }
    clearBuffer();

    int idx = findOrgById(id);
    if (idx == -1) {
        printf("Organisation with ID %d not found.\n", id);
        return;
    }

    printf("Are you sure you want to delete '%s'? (1 for Yes / 0 for No): ", orgs[idx].name);
    int confirm;
    if (scanf("%d", &confirm) == 1 && confirm == 1) {
        for (int i = idx; i < org_count - 1; i++) {
            orgs[i] = orgs[i + 1];
        }
        org_count--;
        printf("Organisation deleted successfully.\n");
    } else {
        printf("Deletion cancelled.\n");
    }
    clearBuffer();
}

int main() {
    loadData();

    int choice;
    while (1) {
        printf("\n============================================\n");
        printf("       ORGANISATION MANAGEMENT SYSTEM       \n");
        printf("============================================\n");
        printf(" 1. Add New Organisation\n");
        printf(" 2. Display All Organisations\n");
        printf(" 3. View Organisation Details & Employees\n");
        printf(" 4. Add Employee to Organisation\n");
        printf(" 5. Search Organisations (Name/Location/Cat)\n");
        printf(" 6. Search Employees (Name/Designation)\n");
        printf(" 7. View Overall Statistics\n");
        printf(" 8. Delete Organisation\n");
        printf(" 9. Save Data\n");
        printf(" 0. Exit\n");
        printf("============================================\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            clearBuffer();
            continue;
        }
        clearBuffer();

        switch (choice) {
            case 1:
                addOrganisation();
                break;
            case 2:
                displayAllOrganisations();
                break;
            case 3:
                viewOrganisationDetails();
                break;
            case 4:
                addEmployeeToOrganisation();
                break;
            case 5:
                searchOrganisations();
                break;
            case 6:
                searchEmployees();
                break;
            case 7:
                showOverallStats();
                break;
            case 8:
                deleteOrganisation();
                break;
            case 9:
                saveData();
                break;
            case 0:
                printf("\nSaving changes before exit...\n");
                saveData();
                printf("Thank you for using Organisation Management System. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please select an option between 0 and 9.\n");
        }
    }

    return 0;
}
